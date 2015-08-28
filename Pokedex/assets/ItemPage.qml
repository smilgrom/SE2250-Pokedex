import bb.cascades 1.2

Page {
    property alias name: titlebar.title
    property alias type: type_label.text // "type" property of this screen is mapped to the text field of the UI element with the id of "type_label"
    // TODO: create other aliases that will be set from main.qml
    
    titleBar: TitleBar {
        id: titlebar
    }
    Container {
        Container { // Make a container to show pokemon type
            layout: StackLayout { // Lay out sub items left-to-right
                orientation: LayoutOrientation.LeftToRight
            }
            Label { 
                text: "Type: "
                textStyle.fontWeight: FontWeight.Bold
                textStyle.color: Color.DarkRed // Show this text
            } 
	        Label {
                id: type_label // Name this as type_label so that the property alias above can set the text property of this item
            } 
        }
        // TODO: Add other containers to display other stats of the pokemon
    }
}