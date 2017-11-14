#include "dataservices.h"

DataServices::DataServices()
{

}

QList<person> DataServices::DocFile(QString s){
    QList<person> list;
    QFile file(s);
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, "..", "this file isn't opened");
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
                    }
                    list.append(a);
                }
            }
        }

    }
    file.close();
    return list;
}

void DataServices::GhiFile(QList<person> list, QString s){
    QFile file(s);
    if(!file.open(QIODevice::WriteOnly)){
        QMessageBox::warning(this, "..", "this file isn't opened");
    }
    else{
        QXmlStreamWriter writer(&file);
        writer.setAutoFormatting(true);
        writer.writeStartDocument();

            writer.writeStartElement("People");
            for(int i = 0; i < list.count(); i++){
                person a = list.at(i);
                writer.writeStartElement("Person");
                    writer.writeAttribute("ID", QString::number(a.ID));
                    writer.writeTextElement("Name", a.name);
                    writer.writeTextElement("Age", QString::number(a.age));
                writer.writeEndElement();
            }
            writer.writeEndElement();

        writer.writeEndDocument();
    }
}
