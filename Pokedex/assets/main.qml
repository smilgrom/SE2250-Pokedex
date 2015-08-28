import bb.cascades 1.2
NavigationPane {
    id: nav
    Menu.definition: MenuDefinition {
        actions: [
            ActionItem {
                title: "Language"
                onTriggered: {
                    nav.push(languageSelection)
                }            
            }
        ]
    }
    Page {
        Container {
            Container {
                background: Color.create("#4F2683")
                horizontalAlignment: HorizontalAlignment.Fill
                Label {
                    id: title
                    text: "SE 2250 Project - Pokédex"
                    textStyle.fontSize: FontSize.Medium
                    textStyle.color: Color.White
                    textStyle.fontWeight: FontWeight.Bold
                    horizontalAlignment: HorizontalAlignment.Center
                    objectName: "title"
                }
            }
            DropDown {
                id: pokemon_types
                title: "Pokémon Type"
                onSelectedIndexChanged: {
                    pokedex.typeSelected(selectedValue)
                }
                options: Option {
                    text: "All Types"
                    value: -1
                    selected: true
                }
                objectName: "pokemon_types"
            }
            Label { // status text
                id: status
                text: ""
                objectName: "pokedex_status"
                textStyle.fontSize: FontSize.Small
                textStyle.color: Color.DarkMagenta
                horizontalAlignment: HorizontalAlignment.Center
            }
            ListView { // This is the 'view' part of the model-view-controller
                dataModel: pokemon_list // Connect 'pokemon_list' as the 'model' for this view
                
                onTriggered: { // What to do when user selects an item
                    if (indexPath.length == 1) { // this is a first level item
                        var chosenItem = dataModel.data(indexPath);	// Get the data from dataModel
                        var contentpage = itemPageDefinition.createObject(); // create the sub-page
                        
                        contentpage.name = chosenItem.name // Set the properties. See property alias statements in itemPage.qml 
                        contentpage.type = chosenItem.type
                        // TODO: set other stats
                        nav.push(contentpage); // Show the page
                    }
                }
            }
        
        }
    
    }
    attachedObjects: [
        ComponentDefinition {
            id: itemPageDefinition
            source: "ItemPage.qml"
        },
        Page {
            id: languageSelection
            titleBar: TitleBar {
                title: "Select Language"
            }
            RadioGroup {
                id: pokedex_languages
                objectName: "pokedex_languages"
                onSelectedIndexChanged: {
                    pokedex.languageSelected(selectedValue)
                }
            }
        
        }
    ]
    onPopTransitionEnded: {
        page.destroy();
    }
}
