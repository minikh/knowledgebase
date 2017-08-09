import javafx.application.Application;
import javafx.beans.property.adapter.JavaBeanIntegerPropertyBuilder;
import javafx.beans.value.ObservableValue;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableColumn.CellDataFeatures;
import javafx.scene.control.TableView;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.HBox;
import javafx.stage.Stage;
import javafx.util.Callback;

import java.util.Random;

//import java.util.stream.Collectors;
//import java.util.stream.IntStream;


public class Main extends Application {
    @Override
    public void start(Stage primaryStage) {
        try {
            BorderPane root = new BorderPane();
            final TableView<Item> table = new TableView<>();
            TableColumn<Item, String> nameCol = new TableColumn<>("Name1");
            TableColumn<Item, Number> valueCol = new TableColumn<>("Value1");
//            nameCol.setCellValueFactory(new Callback<TableColumn.CellDataFeatures<Item,String>, ObservableValue<String>>() {
//                @Override
//                public ObservableValue<String> call(CellDataFeatures<Item, String> data) {
//                    try {
//                        return new JavaBeanStringPropertyBuilder().bean(data.getValue()).name("name").build();
//                    } catch (Exception e) {
//                        e.printStackTrace();
//                        throw new RuntimeException(e);
//                    }
//                }
//            });
            valueCol.setCellValueFactory(new Callback<TableColumn.CellDataFeatures<Item,Number>, ObservableValue<Number>>() {

                @Override
                public ObservableValue<Number> call(CellDataFeatures<Item, Number> data) {
                    try {
                        return new JavaBeanIntegerPropertyBuilder().bean(data.getValue()).name("value").build();
                    } catch (Exception e) {
                        e.printStackTrace();
                        throw new RuntimeException(e);
                    }
                }
            });
            table.getColumns().addAll(nameCol, valueCol);

            Random rng = new Random();
            for (int i=1; i<=20; i++) {
                table.getItems().add(new Item("Item "+i, rng.nextInt(50)));
            }

            Button incrementButton = new Button("Increment");
            incrementButton.setOnAction(new EventHandler<ActionEvent>() {
                @Override
                public void handle(ActionEvent event) {
                    for (Item item : table.getSelectionModel().getSelectedItems()) {
                        item.setValue(item.getValue() + 1);
                    }
                }
            });

            Button showDataButton = new Button("Show data");
            showDataButton.setOnAction(new EventHandler<ActionEvent>() {

                @Override
                public void handle(ActionEvent event) {
                    for (Item item : table.getItems()) {
                        System.out.println(item);
                    }
                }
            });

            HBox controls = new HBox(5);
            controls.getChildren().addAll(incrementButton, showDataButton);
            controls.setPadding(new Insets(10));
            controls.setAlignment(Pos.CENTER);
            root.setCenter(table);
            root.setBottom(controls);
            Scene scene = new Scene(root,600,400);

            primaryStage.setScene(scene);
            primaryStage.show();
        } catch(Exception e) {
            e.printStackTrace();
        }
    }
//    public class Item {
//        private String name ;
//        private int value ;
//        private final PropertyChangeSupport propertySupport ;
//
//        public Item(String name, int value) {
//            this.name = name;
//            this.value = value;
//            this.propertySupport = new PropertyChangeSupport(this);
//        }
//        public String getName() {
//            return name;
//        }
//        public void setName(String name) {
//            String oldName = this.name ;
//            this.name = name;
//            propertySupport.firePropertyChange("name", oldName, name);
//        }
//        public int getValue() {
//            return value;
//        }
//        public void setValue(int value) {
//            int oldValue = this.value ;
//            this.value = value;
//            propertySupport.firePropertyChange("value", oldValue, value);
//        }
//
////        public void addPropertyChangeListener(PropertyChangeListener listener) {
////            propertySupport.addPropertyChangeListener(listener);
////        }
//        @Override
//        public String toString() {
//            return name +": "+value ;
//        }
//    }
    public static void main(String[] args) {
        launch(args);
    }
}