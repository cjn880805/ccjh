ITEM_BEGIN(CIdetectbox);

virtual void create(int nFlag = 0)		
{
	set_name("��ɫ������","musicbox");
	set_weight(30000);
	set("value",1500);
};

virtual int Can_Use()
{
	return 1;
}

virtual int do_use(CChar * me, CContainer * target)
{
	say("һ��СС�������У�����ߵ�����ܷ���������������", me);
	AddMenuItem("ߵһ��", "$9click $1 ���ռ���", me); 
	AddMenuItem("ߵ����", "$9click $1 ����", me); 
	AddMenuItem("ߵ����", "$9click $1 �����Ϻ�ɢ", me); 
	AddMenuItem("ߵ����", "$9click $1 ����", me); 
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
		return notify_fail("��ķ������㣡");

	me->add("mp", -30);

	message_vision("$N����һ��СС����ɫ���ӣ���������˼��¡�" , me);
	message_vision("ֻ�������з���һ������������" , me);
//	message_vision(snprintf(msg, 255, "���г���һ���ţ�%s��������������", dest),me);

	char shtgt[255];
	CRoom * troom;
	troom=load_room("��ɽ");

	LONG a;

	CContainer * astar;

	if(strcmp(dest, "����") == 0)
	{
		a=troom->query("task4");
		astar=find_object(a);
		if (!astar)
		{
			tell_object(me,"�����������Σ�����ʲô����Ҳû�У�ֻ�����������������ڿ��л��졣");
			return 1;
		}
			
		while(astar->environment())
			astar = astar->environment();
				
		snprintf(shtgt, 255, "%s", astar->querystr("base_name"));
		
		
//		snprintf(shtgt, 255, "%s",troom->querystr("task4").c_str());

	}
	if(strcmp(dest, "�����Ϻ�ɢ") == 0)
	{
		a=troom->query("task3");
		astar=find_object(a);
		if (!astar)
		{
			tell_object(me,"�����������Σ�����ʲô����Ҳû�У�ֻ�����������������ڿ��л��졣");
			return 1;
		}

		while(astar->environment())
			astar = astar->environment();
				
		snprintf(shtgt, 255, "%s", astar->querystr("base_name"));
	
//		snprintf(shtgt, 255, "%s",troom->querystr("task3").c_str());

	}
	if(strcmp(dest, "����") == 0)
	{
		a=troom->query("task2");
		astar=find_object(a);
		if (!astar)
		{
			tell_object(me,"�����������Σ�����ʲô����Ҳû�У�ֻ�����������������ڿ��л��졣");
			return 1;
		}

		while(astar->environment())
			astar = astar->environment();
				
		snprintf(shtgt, 255, "%s", astar->querystr("base_name"));

	}
	if(strcmp(dest, "���ռ���") == 0)
	{
		a=troom->query("task1");
		astar=find_object(a);
		if (!astar)
		{
			tell_object(me,"�����������Σ�����ʲô����Ҳû�У�ֻ�����������������ڿ��л��졣");
			return 1;
		}

		while(astar->environment())
			astar = astar->environment();
				
		snprintf(shtgt, 255, "%s", astar->querystr("base_name"));

//		snprintf(shtgt, 255, "%s",troom->querystr("task1").c_str());

	}

//	message_vision(snprintf(msg, 255, "���г���һ���ţ�%s��������������", shtgt),me);


	static struct{
		char area[10];
		int  x;			//����
		int	 y;			//����
	} loc[50] = {				// 0~10
		{"����", 9,7,},
		{"����", 4,2,},
		{"����", 7,1,},
		{"����", 11,15,},
		{"����", 5,7,},
		{"�ɶ�", 3,4,},
		{"����", 4,2,},
		{"����", 2,3,},
		{"��ɽ", 7,2,},
		{"����", 11,5,},
		{"��Ĺ", 4,6,},
		{"����", 14,16,},
		{"����", 11,6,},
		{"����", 13,5,},
		{"��ľ", 6,13,},
		{"��ɽ", 9,4,},
		{"����", 9,3,},
		{"��ɽ", 10,13,},
		{"��ɽ", 8,8,},
		{"�ƺ�", 10,10,},
		{"����", 14,6,},
		{"����", 4,15,},
		{"����", 2,9,},
		{"÷ׯ", 15,5,},
		{"����", 3,6,},
		{"����", 12,10,},
		{"���", 3,5,},
		{"Ȫ��", 13,2,},
		{"����", 11,12,},
		{"����", 15,12,},
		{"����", 12,6,},
		{"̨��", 15,1,},
		{"̩ɽ", 14,9,},
		{"�һ�", 15,6,},
		{"����", 3,2,},
		{"���", 2,2,},
		{"�䵱", 4,5,},
		{"�书", 6,6,},
		{"����", 4,7,},
		{"����",7,1,},
		{"����", 8,7,},
		{"����", 3,8,},
		{"ѩɽ", 0,5,},
		{"Ѫ��", 1,5,},
		{"����", 12,5,},
		{"����", 10,8,},
		{"����", 5,6,},
		{"����", 6,5,},
		{"��ɽ", 12,12,},
		{"��ң", 9,6,},
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
	

	string sol="������";
	
	if (ax>bx)
		sol+="��";
	if (ax<bx)
		sol+="��";
	if (ay>by)
		sol+="��";
	if (ay<by)
		sol+="��";

	if (ax==bx && ay==by)
		sol+="����";
	else
		sol+="��";
	
	sol+="�����л���������";

	snprintf(msg, 255, "%s", sol.c_str());
	tell_object(me,msg);

	if(!random(3))
	{
		tell_object(me,"������������˵�����ʹ���������������ˣ�");
		destruct(this);
	}


//	CRoom * r = load_room(dest);
//	tell_room(r, snprintf(msg, 255, "���г���һ���ţ�%s��������������", me->name()));
//	me->move(r);	    
	return 1;
}

ITEM_END;


