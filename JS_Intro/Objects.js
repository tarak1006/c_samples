/*
OVERVIEW: 	Javascript objects are essentially containers for named values. In this activity, you will write
			a function that inspects an object and returns its property names.
			Example: var car = {make: "Honda", model:"Civic", color:"Silver"}
			GetObjectPropertyNames() should return ["make","model","color"] 

INPUTS: 	obj - A javascript object

OUTPUT: 	array containing the property names of obj.

ERROR CASES: return null if obj is null or is not a Javascript object.
*/
exports.GetObjectPropertyNames = function(obj){
	if (obj==null || typeof(obj)!='object')
		return null;
	else
		return Object.getOwnPropertyNames(obj);
 


}

/*
OVERVIEW: 	Javascript objects are essentially containers for named values. In this activity, you will write
			a function that inspects an object and returns its property values.
			Example: var car = {make: "Honda", model:"Civic", color:"Silver"}
			GetObjectPropertyValues() should return ["Honda","Civic","Silver"] 

INPUTS: 	obj - A javascript object

OUTPUT: 	array containing the property names of obj.

ERROR CASES: return null if obj is null or is not a Javascript object.
*/
exports.GetObjectPropertyValues = function(obj) {
	if(obj==null || typeof(obj)!='object')
		return null;
	else{
	a=[]
	for(var name in obj){
		a.push(obj[name]);
	}
}
return a;


}
var car = {make: "Honda", model:"Civic", color:"Silver"}
console.log(exports.GetObjectPropertyValues(car));