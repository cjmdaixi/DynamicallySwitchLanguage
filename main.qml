import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World") + $app.langToken

    Button{
        id: btn
        anchors{top: parent.top; left: parent.left; margins: 20}
        text: qsTr("Button") + $app.langToken
    }

    ListView{
        id: listView
        anchors{top: btn.bottom; left: parent.left; margins: 20}
        height: 100
        spacing: 5
        model: ListModel{
            ListElement{
                textVal: QT_TR_NOOP("First Item")
            }
            ListElement{
                textVal: QT_TR_NOOP("Second Item")
            }
            ListElement{
                textVal: QT_TR_NOOP("Third Item")
            }
        }

        delegate: Label{
            text: qsTr(textVal) + $app.langToken
            font.pixelSize: 15
        }
    }

    RowLayout{
        anchors.centerIn: parent
        RadioButton{
            id: selectEnglishRadioButton
            checked: true
            text: "English"
            onClicked: {
                $app.language = "en";
            }
        }
        RadioButton{
            id: selectChineseRadioButton
            text: "中文"
            onClicked: {
                $app.language = "zh";
            }
        }
    }


}
