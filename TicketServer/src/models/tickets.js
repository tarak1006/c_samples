/**
 * Fill this method to create required tables for storing tickets.
 *
 * Also, this method should clear off any existing data.
 *
 * @param callback Send the err and result of the DDL operation appropriately
 */
 var mysql=require("mysql")
 var dbHelper = require("./../../src/models/databaseHelper");
exports.setupTicketsTable = function (callback) {
	var dbConfig = dbHelper.getDBConfig();
        


//CREATE SCHEMA dbConfig["database"];
console.log(dbConfig["database"]);
console.log(dbConfig);

/*
CREATE  TABLE dbConfig["database"].`tickets` (

  `pnr` INT NOT NULL,

  `src` VARCHAR(70) NOT NULL ,

  `dest` VARCHAR(150) NOT NULL ,
  `name` VARCHAR(70) NOT NULL ,
  `doj`  VARCHAR(20) NOT NULL ,
  `facilities` VARCHAR(400) NOT NULL ,
  PRIMARY KEY (`pnr`) );
 */

};

/*************************/
exports.getTickets = function(callback) {
	var connection = dbHelper.getConnection(dbConfig);
        
	
	connection.connect();
	
	connection.query("select * from tickets",function(err, result){
			if(err){
				console.log(err);
			}
			dbHelper.endConnection();

			callback(err,result);
		});

};

/**
 * Method is used to get task with given id.
 * @param id Id to the task
 * @param callback callback handler with error and result.
 */
exports.getTicketByPnr = function(id, callback) {
	var connection = dbHelper.getConnection(dbConfig);
	var id1=parseInt(id);
        
	
	connection.connect();
connection.query("select * from tickets WHERE pnr = ?", 
			[id1],function(err, result){
			if(err){
				console.log(err);
			}
			dbHelper.endConnection();

			callback(err,result);
		});

};

/**
 * Method is used to delete a task.
 * @param task json object having tasks fields ("id, tasks", "descriptions")
 * @param callback callback handler with error and result.
 */
exports.createTicket = function(ticket, callback) {
	var connection = dbHelper.getConnection(dbConfig);
        
	console.log("Create");
	connection.connect();
	connection.query("insert into tickets SET ?",
	[100001,ticket],

    function(err, result){
     	if(err){
     		console.log(err);
     		process.exit(1);
     	}
     	
     	console.log("Contact insert result: ", result);
     	dbHelper.endConnection();
     	callback(err,result);


     	});

};


