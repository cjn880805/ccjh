//dog
//2001-04-14

ITEM_BEGIN(CIhammer_book);

void create(int nFlag = 0)	
{
	set_name( "《现代铸剑技术研究参考》");	

 	set_weight(200);	

	set("unit", "本");
 	set("long", "这是著名铸剑师欧冶子所写的书，记载了如何运用技巧锻造兵器的方法。");
	set("value",  35000 );
	set("material", "paper");
	set("skill/name","hammer");	
	set("skill/exp_required", 200 );
	set("skill/jing_cost",   10+random(10));
	set("skill/difficulty", 20 );
	set("skill/max_skill", 190 );
	set("skill/min_skill", 25 ); 	

};

ITEM_END;
