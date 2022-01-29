import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.1


/*Rectangle { objectName: "rect"; color: "gray"; width: 30; height: 30; border { width: 1; color: "black" }
    MouseArea {
            id: area
            anchors.fill: parent
            onClicked: {
                parent.objectName = "current"
                parent.color = "red" //when you shoot rectangle turns red, one color - bad ...
                send((parent.x+mouseX)/30, (parent.y+mouseY)/30 )
               }
         }
  }*/

Button {
       id: buttonTest
       objectName: "buttonTest"

       signal clickedButton(string str)
       onClicked: {
           buttonTest.clickedButton("clicked !")
       }
   }
