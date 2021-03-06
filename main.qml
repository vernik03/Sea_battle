import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.12
import QtQml 2.15

Window {
    signal send(int x, int y, int index)
    width: 300
    height: 300
    visible: true

    Grid {

        x: 0; y: 0; width: 300; height: 300
            columns: 10; rows: 10; spacing: 0

        Repeater {
           id: repeater
           model: 100
           Rectangle { color: "gray"; width: 30; height: 30; border { width: 1; color: "black" }
               property int number
               number: index

               Connections {
                   target: object
                   onCppSignal:{
                       if(number==index){
                           if(isShip){
                               console.log("good shot!");
                           }else{
                               console.log("missed!");
                           }
                           if(isShip==true){
                                color = "red"
                           }else{
                               color = "blue"
                           }
                       }
                   }
               }

               MouseArea {
                       anchors.fill: parent
                       onClicked: {
                           send((parent.x+mouseX)/30, (parent.y+mouseY)/30, parent.number)
                       }
               }
            }
        }
    }
}
