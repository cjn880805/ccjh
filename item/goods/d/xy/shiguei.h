//shiguei.h 书架
ITEM_BEGIN(CIshiguei)

virtual void create(int nFlag = 0)		
{
	set_name("书架","shi guei");
	set("unit", "个");
	set("no_get", "");
	set_weight(1);
};

virtual int do_look(CChar * me)
{
	say("这是一个木制书架，靠在墙边排的整整齐齐,架上所列，皆是各门各派武功的图谱经籍。", me);
	if(me->query_temp("xy/renwu6_4") && me->query("xy/renwu6") )
	{
		static char book1[15][20]={"洗髓经","独孤九剑剑谱","葵花宝典","金蛇秘芨","紫霞密芨","天山折梅手法图","昊天掌法谱","玉女心经","玉女剑谱","神龙八式手法","旋风扫叶腿法","韦陀棍法","连城秘籍","东洋刀法","梦云刀法"};
		static char book2[15][20]={"醉棍棍法","无常杖法","普渡杖法","伏魔剑法","达摩剑法","龙爪功法","鹰爪功法","拈花指法","一指禅功","慈悲刀法","修罗刀法","华山剑谱","天羽奇剑剑谱","辟邪剑谱","情深刀法"};
		static char book3[17][20]={"密宗心经","妙手空空入门秘籍","九阴真经","九阳真经","太极十三势","星宿毒经","胡家刀谱","中平枪法","太玄功","金蛇游身掌法","金蛇锥法","金蛇剑法","五虎断门刀法","销魂剑法","相思刀法","华光流影剑法","冰天剑法"};
		static char book4[20][20]={"五毒掌法","五毒心法","五毒神功","五毒鞭法","泰山剑法","嵩山剑法","衡山剑法","恒山剑法","凌虚步法","绝门棍法","金乌刀法","寒星八打","鬼魅身法","长拳拳法","铁笛魔功","五文爪法","薇安剑法","唐手秘籍","神照心法","寒霜刀法"};
		CContainer * env=me->environment();
		if(env->query("index"))
		{
			int i;
			switch(env->query("index"))
			{
			case 1:
				for(i=0;i<15;i++)
				{
					AddMenuItem(book1[i], "$9na $1", me);
				}
				break;
			case 2:
				for(i=0;i<15;i++)
				{
					AddMenuItem(book2[i], "$9na $1", me);
				}
				break;
			case 3:
				for(i=0;i<17;i++)
				{
					AddMenuItem(book3[i], "$9na $1", me);
				}
				break;
			case 4:
				for(i=0;i<20;i++)
				{
					AddMenuItem(book4[i], "$9na $1", me);
				}
				break;
			}
		}
	}
	SendMenu(me);
	
	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(me->query_temp("xy/renwu6_4") && me->query("xy/renwu6") )
	{
		if(!strcmp(comm, "na")  )
		{
			say("你拿起书看了一会儿，却发现怎么也看不清上面的写着些什么！",me);
			SendMenu(me);
			return 1;
		}
	}
	return 0;
}

ITEM_END;




