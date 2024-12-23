
NPC_BEGIN(CNpub_yicai);

virtual void create()
{
	set_name("怡采科技",  "echoicetech");

	set("icon", waiter);
	set("gender", "男性" );
	set("age", 49);
	set("per", 40);
	set("grant", 60);
	set("long","怡采科技有限公司的主营业务是：国内外知名游戏在中国的制作、发行 ，是一家集代理、策划、生产、销售、渠道于一体的软件高科技公司。 ");
	set("attitude", "friendly");

	set("file_name", querystr("base_name"));

	Load();
	set("no_huan",1);
}

int Save()
{
	char msg[255];
	return SaveToLocal(snprintf(msg, 255, "data/npc/%s.o", querystr("file_name")), &_M);
}

int Load()
{
	char msg[255];
	return LoadFromLocal(snprintf(msg, 255, "data/npc/%s.o", querystr("file_name")), &_M);	
}

int accept_object(CChar * me, CContainer * item)
{
	char msg[255];
	
	//检查系统时间
	time_t t;	
	struct tm * newtime;
	
	time(&t);
	newtime = localtime(&t); 
	
	int month = newtime->tm_mon + 1;
	int day = newtime->tm_mday;

	if(EQUALSTR(item->querystr("base_name"), "yicai_book1"))
	{
		snprintf(msg, 255, "%d月%d日/战争指挥官", month, day);
		if(!query(msg))
		{
			set(msg,atoi(me->id(1)));
			destruct(item);
			command(snprintf(msg, 255, "wiz 0 $HIW深圳金智塔和怡采科技$COM恭喜$HIR%s(%s)$COM赢得今日大奖,$HIR%s(%s)$COM将可以获得由怡采科技提供的一套$HIW《战争指挥官》$COM游戏。\n", me->name(1),me->id(1),me->name(1),me->id(1)));
			tell_object(me,"$HIW深圳金智塔和怡采科技恭喜你赢得今日大奖，您将可以获得由怡采科技提供的一套《战争指挥官》游戏。$COM");
			tell_object(me,snprintf(msg, 255, "$HIW请您于%d月%d日下午访问$HIRhttp://mail.gameking.com.cn/mail/ccjh/yc_huodong.htm$HIW,登记您的相关资料，以方便我们给您寄出奖品。$COM",month, day+1));
			Save();
			return 1;
		}
		else
		{
			tell_object(me,snprintf(msg, 255, "$HIW很抱歉今日$HIR%d$COM朋友已经领取了由深圳金智塔和怡采科技提供的奖品，请您明天早些时间再来。$COM",query(msg)));
		}
	}
	else if(EQUALSTR(item->querystr("base_name"), "yicai_book2"))
	{
		char msg1[255];
		snprintf(msg1, 255, "%d月%d日/猪兔大战总数", month, day);
		snprintf(msg, 255, "%d月%d日/猪兔大战%d", month, day,query(msg1));
		if(!query(msg) && query(msg1)<4)
		{
			set(msg,atoi(me->id(1)));
			add(msg1,1);
			destruct(item);
			Save();
			command(snprintf(msg, 255, "wiz 0 $HIW深圳金智塔和怡采科技$COM恭喜$HIR%s(%s)$COM赢得今日大奖,$HIR%s(%s)$COM将可以获得由怡采科技提供的一套$HIW《猪兔大战》$COM游戏。\n", me->name(1),me->id(1),me->name(1),me->id(1)));
			tell_object(me,"$HIW深圳金智塔和怡采科技恭喜你赢得今日大奖，您将可以获得由怡采科技提供的一套《猪兔大战》游戏。$COM");
			tell_object(me,snprintf(msg, 255, "$HIW请您于%d月%d日下午访问$HIRhttp://mail.gameking.com.cn/mail/ccjh/yc_huodong.htm$HIW,登记您的相关资料，以方便我们给您寄出奖品。$COM",month, day+1));
			return 1;
		}
		else
		{
			tell_object(me,"$HIW很抱歉今日由深圳金智塔和怡采科技提供的奖品《猪兔大战》奖品已经领取完了，请您明天早些时间再来。$COM");
		}
	}
	return 0;
}

NPC_END;



