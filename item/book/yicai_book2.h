//yicai_book2.h
//怡采科技 猪兔大战

ITEM_BEGIN(CIyicai_book2);

virtual void create(int nFlag = 0)		
{
	set_name( "「猪兔大战」");	

 	set_weight(500);	
	set("value", 5000);

	set("unit", "本");
	set("long", "「猪兔大战」是一个以是由FISHTANK公司开发，怡采科技最新代理的即时战略游戏，共有30个剧情任务，并且支持多人对战，包括死亡模式、夺旗模式和时间生存模式等。");

};

ITEM_END;
