//yicai_book1.h
//怡采科技 战争指挥官

ITEM_BEGIN(CIyicai_book1);

virtual void create(int nFlag = 0)		
{
	set_name( "「战争指挥官」");	

 	set_weight(500);	
	set("value", 5000);

	set("unit", "本");
	set("long", "「战争指挥官」是一个以二次大战为主题的即时战略游戏，游戏由德国Independent Arts开发，CDV互动发行，国内由怡采科技代理。");

};

ITEM_END;
