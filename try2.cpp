e_o = row.find(c);
if(e_o){
	if(!c_even && !x_even)
		return false;
	else if(c_even && x_even)
		return false;
}
else{
	if(!c_even && x_even)
		return false;
	else if(!c_even && !x_even)
		return false;
}