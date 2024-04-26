import sqlConnection as sql
import arduinoConnection as ard

cnx = sql.configSql()
cursor = sql.createCursor(cnx)

mysql = sql.MySQL(cursor)

arduino = ard.Arduino()


result = mysql.getAll("select * from Lightings")[0]


fullHouse = result[1]
Room = result[2]
Bedroom = result[3]
Kitchen = result[4]

def getBool(value):
    return value == 1

print(arduino.write_read(f"{getBool(Room)} room".lower()))