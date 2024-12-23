ITEM_BEGIN(CIpixie_sword_book);

virtual void create(int nFlag = 0)		
{
	set_name( "辟邪剑谱");	

 	set_weight(600);		

	set("unit", "本");
 	set("long", "这是一本辟邪剑谱,供自我修习辟邪剑法。不过这本书并不要求自宫, 真有点怪。");
	set("value",  1000 );
	set("material", "paper");
	set("skill/name","pixie_sword");
	set("skill/exp_required",  10000);
	set("skill/sen_cost",   30 );	
	set("skill/difficulty", 30 );
	set("skill/max_skill",  100);
	set("skill/min_skill", 0l );  
	

};

ITEM_END;
