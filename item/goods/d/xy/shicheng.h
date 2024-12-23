//shicheng.h 石秤
ITEM_BEGIN(CIshicheng)

virtual void create(int nFlag = 0)		
{
	set_name("石秤","shi cheng");
	set("unit", "杆");
	set("no_get", "");
	set_weight(1);
};


virtual int do_look(CChar * me)
{
	say("这是一杆凌空悬于室中石秤，秤盘也是用石料磨成，似乎可以往里面放些什么东西。", me);
	if(me->query_temp("xy/renwu6_2") && me->query("xy/renwu6"))
	{
		AddMenuItem("放置石珠子", "$9fang $1", me);
	}
	SendMenu(me);

	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(me->query_temp("xy/renwu6_2") && me->query("xy/renwu6"))
	{
		if(!strcmp(comm, "fang")  )
			return do_fang(me, arg);

		if(!strcmp(comm, "nine") )
		{
			return do_fang1(me, 9);
		}
		if(!strcmp(comm, "eight") )
		{
			return do_fang1(me, 8);
		}
		if(!strcmp(comm, "seven") )
		{
			return do_fang1(me, 7);
		}
		if(!strcmp(comm, "six") )
		{
			return do_fang1(me, 6);
		}
		if(!strcmp(comm, "five") )
		{
			return do_fang1(me, 5);
		}
		if(!strcmp(comm, "four") )
		{
			return do_fang1(me, 4);
		}
		if(!strcmp(comm, "three") )
		{
			return do_fang1(me, 3);
		}
		if(!strcmp(comm, "two") )
		{
			return do_fang1(me, 2);
		}
		if(!strcmp(comm, "one") )
		{
			return do_fang1(me, 1);
		}
	}
	return 0;
}

int do_fang1(CChar *me, int num)
{
	char msg[255],str[255];
	CContainer * shikuai;
	shikuai=me->present("shi kuai");
	if(shikuai && shikuai->Query_Amount()>=num)
	{
		CContainer * env=me->environment();
		if(env->query("index"))
		{
			snprintf(msg, 255,"xy/renwu6_3_%d",env->query("index"));
			if(!me->query_temp(msg))
			{
				me->set_temp(msg,num);
				shikuai->set_amount(shikuai->Query_Amount()-num);
				tell_object(me, snprintf(msg, 255,"\n$YEL你从怀中掏出%s枚石珠子，轻轻的放入石秤中。",chinese_number(num, str))); 
				tell_object(me,"$YEL只见石秤缓缓一沉，石室中突然传来一阵隆隆响声，不久就恢复了平静。\n");
				for(int i=1;i<10;i++)
				{
					snprintf(msg, 255,"xy/renwu6_3_%d",i);
					if(me->query_temp(msg))
						me->add_temp("xy/renwu6_3",1);//飞凌阁中已经放置了石珠子的房间数目
				}
				if(me->query_temp("xy/renwu6_3")==9)
				{
					tell_object(me,"$YEL片刻之后，猛然又是一阵巨响，整个石室都随之摇晃起来，隐约中，你似乎听到不远处有巨物出现的声音。\n");
					load_item("shizhu")->move(load_room("逍遥谷飞凌之心"));
				}
				else
					me->delete_temp("xy/renwu6_3");
			}
			else
			{
				tell_object(me,"\n$YEL你发现石秤中已经摆放有了石珠子。\n");
			}
		}
		else
		{
			tell_object(me,"\n$YEL除了作弊，我真不知道你是怎么可能在这里进行任务，警告！！！！\n");
		}
	}
	else
	{
		tell_object(me,snprintf(msg, 255,"\n$YEL你伸手到怀中准备掏出%s枚石珠子放在石秤中，摸了半天却发现拿不出这么多。\n",chinese_number(num, str)));
	}
	return 1;
}

int do_fang(CChar *me, char * arg)
{
	if(me->query_temp("xy/renwu6_2") && me->query("xy/renwu6"))
	{
		CContainer * shikuai;
		shikuai=me->present("shi kuai");
		if(shikuai)
		{
			if(shikuai->Query_Amount()>=9)
			{
				AddMenuItem("放置九枚珠子", "$9nine $1", me);
			}
			if(shikuai->Query_Amount()>=8)
			{
				AddMenuItem("放置八枚珠子", "$9eight $1", me);
			}
			if(shikuai->Query_Amount()>=7)
			{
				AddMenuItem("放置七枚珠子", "$9seven $1", me);
			}
			if(shikuai->Query_Amount()>=6)
			{
				AddMenuItem("放置六枚珠子", "$9six $1", me);
			}
			if(shikuai->Query_Amount()>=5)
			{
				AddMenuItem("放置五枚珠子", "$9five $1", me);
			}
			if(shikuai->Query_Amount()>=4)
			{
				AddMenuItem("放置四枚珠子", "$9four $1", me);
			}
			if(shikuai->Query_Amount()>=3)
			{
				AddMenuItem("放置三枚珠子", "$9three $1", me);
			}
			if(shikuai->Query_Amount()>=2)
			{
				AddMenuItem("放置二枚珠子", "$9two $1", me);
			}
			AddMenuItem("放置一枚珠子", "$9one $1", me);
			SendMenu(me);
		}
	}
	else
	{
		say("\n$YEL你伸手到怀中准备掏出石珠子放在石秤中，摸了半天却发现找不到可以放的东西。\n",me);
		SendMenu(me);
	}
	return 1;
}
ITEM_END;




