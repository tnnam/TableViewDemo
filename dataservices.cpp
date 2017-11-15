#include "dataservices.h"

DataServices::DataServices()
{

}

void DataServices::GhiFile(QList<person> list, QString s){
    QFile file(s);
    if(!file.open(QIODevice::WriteOnly)){
        QMessageBox ms;
        ms.setText("File isn't opened!");
        ms.setStandardButtons(QMessageBox::Ok);
        return;
    }
    else{
        QXmlStreamWriter xmlWriter(&file);
        xmlWriter.setAutoFormatting(true);
        xmlWriter.writeStartDocument();

            xmlWriter.writeStartElement("People");
            for(int i = 0; i < list.count(); i++){
                person a = list.at(i);
                xmlWriter.writeStartElement("Person");
                    xmlWriter.writeAttribute("ID", QString::number(a.ID));
                    xmlWriter.writeTextElement("Name", a.name);
                    xmlWriter.writeTextElement("Age", QString::number(a.age));
                xmlWriter.writeEndElement();
            }
            xmlWriter.writeEndElement();

        xmlWriter.writeEndDocument();
    }
}
QList<person> DataServices::DocFile(QString s){
    QList<person> list;
    QFile file(s);
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox ms;
        ms.setText("File isn't opened!");
        ms.setStandardButtons(QMessageBox::Ok);
    }
    else{
        QXmlStreamReader xmlReader(&file);
        while(!xmlReader.atEnd() && !xmlReader.hasError()){
            QXmlStreamReader::TokenType token = xmlReader.readNext();
            if(token == QXmlStreamReader::StartDocument){
                continue;
            }
            if(token == QXmlStreamReader::StartElement){
                if(xmlReader.name() == "People"){
                    continue;
                }
                else if(xmlReader.name() == "Person"){
                    list = parsePerson(xmlReader);
                }
            }
        }
    }
    file.close();
    return list;
}

QList<person> DataServices::parsePerson(QXmlStreamReader &xmlReader){
    if(xmlReader.tokenType() != QXmlStreamReader::StartElement
        && xmlReader.name() != "Person"){
        QMessageBox ms;
        ms.setText("Fail!");
        ms.setStandardButtons(QMessageBox::Ok);
     }
      QList<person> list;
        person a;
        a.ID = xmlReader.attributes().value("ID").toString().toInt();
        xmlReader.readNext();
        while(!(xmlReader.tokenType() == QXmlStreamReader::EndElement
                && xmlReader.name() == "Person")){
            if(xmlReader.tokenType() == QXmlStreamReader::StartElement){
                if(xmlReader.name() == "Name"){
                    xmlReader.readNext();
                    a.name = xmlReader.text().toString();
                }
                else if(xmlReader.name() == "Age"){
                    xmlReader.readNext();
                    a.age = xmlReader.text().toString().toInt();
                }
            }
            xmlReader.readNext();
            list.append(a);
        }
        return list;
}

DataServices::~DataServices(){

}
QList<Question> questions;
void YourXMLParsingObject::yourXMLParsingMethod(QString filePath){
        QFile* file = new QFile(xmlFilePath);
        if(!file->open(QIODevice::ReadOnly | QIODevice::Text)){
        return;
    }

    QXmlStreamReader xml(file);
    while(!xml.atEnd() && !xml.hasError()){
        QXmlStreamReader::TokenType token = xml.readNext();
        if(token == QXmlStreamReader::StartDocument){
            continue;
        }
        if(token == QXmlStreamReader::StartElement) {
            if(xml.name() == "GlobalVar"){
                globalVar.ID = xml.attributes().value(“ID”).toString().toInt();
                xml.readNext();
                globalVar.text = xml.text().toString();
             }
            if(xml.name() == QuestionSet){
                continue;
            }
            if(xml.name() == "Question") {
                this->parseQuestion(xml);
            }
         }
     }
}
void YourXMLParsingObject::parseQuestion(QXmlStreamReader& xml){
    if(xml.tokenType() != QXmlStreamReader::StartElement
        && xml.name() != "Question"){
        qDebug() << "Called XML parseQuestionElement "
            << "without a question Element in the XML stream!";
         return;
     }
     Question* newQuestion = new Question();
     newQuestion->ID = xml.attributes().value("ID").toString().toInt();
     xml.readNext();
     while(!(xml.tokenType() == QXmlStreamReader::EndElement
            && xml.name() == "Question")){
         if(xml.tokenType() == QXmlStreamReader::StartElement){
            if(xml.name() == "Text"){
                xml.readNext();
                    newQuestion->questionText = xml.text().toString();
            }
            if(xml.name() == "Answer"){
                xml.readNext();
                newQuestion->answerText = xml.text().toString();
            }
         }
         xml.readNext();
     }
     questions.add(newQuestion);
     return;
}
