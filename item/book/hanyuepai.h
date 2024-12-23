ITEM_BEGIN(CIhanyuepai);

virtual void create(int nFlag = 0)		
{
	set_name( "ÌìÑÄº®ÔÂÅÆ");	

 	set_weight(30000);

	set("unit", "¿é");
	set("value",  100000 );
	set("material", "silk");
	
	if (random(2)==0)
		set("skill/name","literate");
	else
		set("skill/name","unarmed");
	

	set("skill/exp_required",  0l);	

	set("skill/jing_cost",   35);	
	set("skill/difficulty", 25 );	

	set("skill/max_skill",  350);
	set("skill/min_skill", 100 );  

//	set("no_drop", 1);
};

ITEM_END;
