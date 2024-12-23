
NPC_BEGIN(CNwiz_106);

void create()
{
	set_name("半桶水", "ban tong shuei");
	
	set("title", "贺岁使者");
	set("long","这就是半桶水巫师，他神情专注地盯着关口前方，准备随时对那些捣乱分子发动攻击。");
	
	set("icon", young_man2);
	set("per",29);
	
	set("gender", "男性");
	set("level", 300);
	set("age", 44);

	set("chat_chance", 3);

	set("no_kill",1);
	
}

virtual char * chat_msg()
{
	switch(random(3))
	{
	case 0:
		return "半桶水睁圆了眼睛大喝道：“你们这些捣乱分子，今天休想从我这儿溜进关去！”";
	case 1:
        return "半桶水在城墙上来回地踱着步，随时留意着外面的情况。";
	case 2:
        return "半桶水满脸严肃的说道：“据探子来报，有破坏分子密谋破坏的日期改了，估计会在二月初二龙抬头前后前来破坏。”";
	}
	
	return 0;
}

int do_talk(CChar * me, char * ask = NULL)
{
	if(!me->query("chunjie/106/ok") )
	{
		if(! strlen(ask))
		{
			AddMenuItem("拜年","bai",me);
			AddMenuItem("帮助守关","shou",me);
		}
		else if(!strcmp(ask, "bai") )
		{
			say("半桶水向你一拱手：“祝你新年平安，万事顺意！”",me);
		}
		else if(!strcmp(ask, "shou") && !query("stop"))
		{
			say("半桶水将你打量了一番，然后说道：“正好，我一个人守关也有些难以应付，不过千万要小心，破坏分子很难对付的。",me);
			say("半桶水接着又笑道：“不过现在可能还为时过早，据探子来报，破坏分子在正月十五前后前来才会出现。”",me);
		}
	}
	SendMenu(me);
	return 1;
}

NPC_END;
