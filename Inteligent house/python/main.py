import sqlConnection as sql
import arduinoConnection as ard
import time




arduino = ard.Arduino()

while(True):
    cnx = sql.configSql()
    cursor = sql.createCursor(cnx)

    mysql = sql.MySQL(cursor)
    result = mysql.getAll("select * from Lightings")[0]
    time.sleep(1)

    fullHouse = result[1]
    Room = result[2]
    Bedroom = result[3]
    Kitchen = result[4]

    def getBool(value):
        return value == 1

    print(arduino.write_read(f"{getBool(fullHouse)} fullHouse".lower()))
    print(arduino.write_read(f"{getBool(Room)} room".lower()))
    print(arduino.write_read(f"{getBool(Bedroom)} bedroom".lower()))
    print(arduino.write_read(f"{getBool(Kitchen)} kitchen".lower()))
    




