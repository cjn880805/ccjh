ITEM_BEGIN(CIdetectbox);

virtual void create(int nFlag = 0)		
{
	set_name("七色七音盒","musicbox");
	set_weight(30000);
	set("value",1500);
};

virtual int Can_Use()
{
	return 1;
}

virtual int do_use(CChar * me, CContainer * target)
{
	say("一个小小的七音盒，轻轻叩动就能发出动听的声音。", me);
	AddMenuItem("叩一下", "$9click $1 红烧鸡翅", me); 
	AddMenuItem("叩两下", "$9click $1 弹珠", me); 
	AddMenuItem("叩三下", "$9click $1 阴阳合和散", me); 
	AddMenuItem("叩四下", "$9click $1 情书", me); 
	SendMenu(me);

    return 1; 
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "click") == 0)
		return do_seek(me, arg);

	return CItem::handle_action(comm, me, arg);
}


int do_seek(CChar * me , char  * dest)
{
	char msg[255];

	if(me->query("mp") < 30)
		return notify_fail("你的法力不足！");

	me->add("mp", -30);

	message_vision("$N摸出一个小小的七色盒子，轻轻的敲了几下。" , me);
	message_vision("只听七音盒发出一阵动听的声音。" , me);
//	message_vision(snprintf(msg, 255, "空中出现一道门，%s从中走了下来。", dest),me);

	char shtgt[255];
	CRoom * troom;
	troom=load_room("佛山");

	LONG a;

	CContainer * astar;

	if(strcmp(dest, "情书") == 0)
	{
		a=troom->query("task4");
		astar=find_object(a);
		if (!astar)
		{
			tell_object(me,"你侧耳倾听半晌，但是什么声音也没有，只有七音盒清脆的鸣叫在空中回响。");
			return 1;
		}
			
		while(astar->environment())
			astar = astar->environment();
				
		snprintf(shtgt, 255, "%s", astar->querystr("base_name"));
		
		
//		snprintf(shtgt, 255, "%s",troom->querystr("task4").c_str());

	}
	if(strcmp(dest, "阴阳合和散") == 0)
	{
		a=troom->query("task3");
		astar=find_object(a);
		if (!astar)
		{
			tell_object(me,"你侧耳倾听半晌，但是什么声音也没有，只有七音盒清脆的鸣叫在空中回响。");
			return 1;
		}

		while(astar->environment())
			astar = astar->environment();
				
		snprintf(shtgt, 255, "%s", astar->querystr("base_name"));
	
//		snprintf(shtgt, 255, "%s",troom->querystr("task3").c_str());

	}
	if(strcmp(dest, "弹珠") == 0)
	{
		a=troom->query("task2");
		astar=find_object(a);
		if (!astar)
		{
			tell_object(me,"你侧耳倾听半晌，但是什么声音也没有，只有七音盒清脆的鸣叫在空中回响。");
			return 1;
		}

		while(astar->environment())
			astar = astar->environment();
				
		snprintf(shtgt, 255, "%s", astar->querystr("base_name"));

	}
	if(strcmp(dest, "红烧鸡翅") == 0)
	{
		a=troom->query("task1");
		astar=find_object(a);
		if (!astar)
		{
			tell_object(me,"你侧耳倾听半晌，但是什么声音也没有，只有七音盒清脆的鸣叫在空中回响。");
			return 1;
		}

		while(astar->environment())
			astar = astar->environment();
				
		snprintf(shtgt, 255, "%s", astar->querystr("base_name"));

//		snprintf(shtgt, 255, "%s",troom->querystr("task1").c_str());

	}

//	message_vision(snprintf(msg, 255, "空中出现一道门，%s从中走了下来。", shtgt),me);


	static struct{
		char area[10];
		int  x;			//Ｘ轴
		int	 y;			//Ｙ轴
	} loc[50] = {				// 0~10
		{"舍身", 9,7,},
		{"大理", 4,2,},
		{"白驼", 7,1,},
		{"北京", 11,15,},
		{"长安", 5,7,},
		{"成都", 3,4,},
		{"大理", 4,2,},
		{"峨嵋", 2,3,},
		{"佛山", 7,2,},
		{"福州", 11,5,},
		{"古墓", 4,6,},
		{"关外", 14,16,},
		{"归云", 11,6,},
		{"杭州", 13,5,},
		{"黑木", 6,13,},
		{"衡山", 9,4,},
		{"衡阳", 9,3,},
		{"恒山", 10,13,},
		{"华山", 8,8,},
		{"黄河", 10,10,},
		{"嘉兴", 14,6,},
		{"灵州", 4,15,},
		{"灵鹫", 2,9,},
		{"梅庄", 15,5,},
		{"明教", 3,6,},
		{"南阳", 12,10,},
		{"青城", 3,5,},
		{"泉州", 13,2,},
		{"少林", 11,12,},
		{"神龙", 15,12,},
		{"苏州", 12,6,},
		{"台湾", 15,1,},
		{"泰山", 14,9,},
		{"桃花", 15,6,},
		{"天龙", 3,2,},
		{"万劫", 2,2,},
		{"武当", 4,5,},
		{"武功", 6,6,},
		{"西域", 4,7,},
		{"侠客",7,1,},
		{"襄阳", 8,7,},
		{"星宿", 3,8,},
		{"雪山", 0,5,},
		{"血刀", 1,5,},
		{"燕子", 12,5,},
		{"扬州", 10,8,},
		{"终南", 5,6,},
		{"重阳", 6,5,},
		{"嵩山", 12,12,},
		{"逍遥", 9,6,},
	};

	int i, ax = 0, ay = 0, bx = 0, by = 0;

	for (i=0; i<50; i++)
	{
		if(strstr(shtgt, loc[i].area))
		{
			ax = loc[i].x;
			ay = loc[i].y;				
			break;
		}
	}

//	tell_object(me,shtgt);
//	tell_object(me,loc[i].area);

	///////////////////////////////////////////////////////////////////////////////
	const char * ptr = (me->environment())->querystr("base_name");

	for (i=0; i<50; i++)
	{
		if(strstr(ptr, loc[i].area))
		{
			bx = loc[i].x;
			by = loc[i].y;
			break;
		}
	}
	////////////////////////////////////////////////////////////////////////////////
	

	string sol="你听到";
	
	if (ax>bx)
		sol+="东";
	if (ax<bx)
		sol+="西";
	if (ay>by)
		sol+="北";
	if (ay<by)
		sol+="南";

	if (ax==bx && ay==by)
		sol+="附近";
	else
		sol+="方";
	
	sol+="隐隐有回音传来。";

	snprintf(msg, 255, "%s", sol.c_str());
	tell_object(me,msg);

	if(!random(3))
	{
		tell_object(me,"七音盒生气的说：你打痛我拉！不和你玩了！");
		destruct(this);
	}


//	CRoom * r = load_room(dest);
//	tell_room(r, snprintf(msg, 255, "空中出现一道门，%s从中走了下来。", me->name()));
//	me->move(r);	    
	return 1;
}

ITEM_END;


