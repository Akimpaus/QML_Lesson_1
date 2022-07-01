import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Window
{
    width: 640
    height: 480
    visible: true
    title: qsTr("Square")


    function geron(a,b,c)
    {
        var p = (a + b + c) / 2
        return Math.sqrt(p * (p - a) * (p - b) * (p - c))
    }

    function lenByCoords(x1, y1, x2, y2)
    {
        var a = x2 - x1
        var b = y2 - y1
        return Math.sqrt( a * a + b * b )
    }

    function geronByCoords(x1, y1, x2, y2, x3, y3)
    {
        var side_a = lenByCoords(x1, y1, x2, y2)
        var side_b = lenByCoords(x1, y1, x3, y3)
        var side_c = lenByCoords(x2, y2, x3, y3)
        console.log(side_a)
        console.log(side_b)
        console.log(side_c)
        return geron(side_a, side_b, side_c)
    }

    Column
    {

        spacing: 10
        anchors.centerIn: parent
        Column
        {
            id: geron_column
            TextField
            {
                id: a
                placeholderText: "side a"
            }

            TextField
            {
                id: b
                placeholderText: "side b"
            }

            TextField
            {
                id: c
                placeholderText: "side c"
            }

            Button
            {
                width: parent.width
                text: "calculate"
                onClicked:
                {
                    result_geron.text = geron(parseFloat(a.text),parseFloat(b.text),parseFloat(c.text))
                }
            }

            TextField
            {
                id: result_geron
                placeholderText: "result"
            }

        }


        Column
        {
            id: coords_geron_column
            Row
            {
                TextField
                {
                    id: x_1
                    placeholderText: "x 1"
                }
                TextField
                {
                    id: y_1
                    placeholderText: "y 1"
                }
            }
            Row
            {
                TextField
                {
                    id: x_2
                    placeholderText: "x 2"
                }
                TextField
                {
                    id: y_2
                    placeholderText: "y 2"
                }
            }
            Row
            {
                TextField
                {
                    id: x_3
                    placeholderText: "x 3"
                }
                TextField
                {
                    id: y_3
                    placeholderText: "y 3"
                }
            }

            Button
            {
                width: parent.width
                text: "calculate"
                onClicked:
                {
                    result_coords_geron.text = geronByCoords
                            (
                                parseFloat(x_1.text),
                                parseFloat(y_1.text),
                                parseFloat(x_2.text),
                                parseFloat(y_2.text),
                                parseFloat(x_3.text),
                                parseFloat(y_3.text)
                            )
                }
            }

            TextField
            {
                width: parent.width
                id: result_coords_geron
                placeholderText: "result"
            }

        }

    }

}
