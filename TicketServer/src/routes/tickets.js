/**
 * Route all the requests to /tickets to this file....
 *
 * Use models/tickets.js to perform appropriate CRUD Operations.
 */

var tickets = require("./../models/tickets");
 var bodyParser = require('body-parser');

console.log("control flow tickets 1");

/**
 * This file will contain the methods to handle requests to /tasks url.
 *
 * Invoke appropriate methods from models/tasks file to perform corresponding DB operations.
 */
var express = require('express');
var router = express.Router();
router.use(bodyParser.urlencoded({ extended: false }));
router.use(bodyParser.json());


/*router.get('/tickets/:pnr', function(req, res, next) {
    tickets.getTicketByPnr(req.params.pnr,function(err,result){

    	res.end(JSON.stringify(result));

    });


   
    

});
*/
router.get('/', function(req, res, next) {
	tickets.getTickets(function(err,result){

    	res.end(JSON.stringify(result));

    });
    
   
    //res.send(JSON.stringify(requested_contact));
});
router.post('/',function(req,res,next){
	console.log("haii tarak");
    var ticket=JSON.parse(req.body);
    console.log(ticket);
    tickets.createTicket(ticket,function(err,result){

    	res.end(JSON.stringify(result));

    });
    
       // res.end(JSON.stringify(contact));

    
});
/*router.put('/:id',function(req,res,next){
        var a=JSON.parse(req.body);
        tasks.updateTaskById (req.params.id,a,function(err,result){

    	res.end(JSON.stringify(result));

    });
     
          // res.statusCode=200;
          // res.end("");

});


router.del('/:id', function(req, res, next) {
	tasks.deleteTaskById (req.params.id,function(err,result){

    	res.end(JSON.stringify(result));

    });

    
   
    
});
*/
