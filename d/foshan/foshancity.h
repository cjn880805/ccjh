
RESIDENT_BEGIN(CRfoshancity);

virtual void create()		
{

	set_name( "佛山");

	set("resident", "佛山");
	set("capacity", 20);

	add_npc("pub_bing");
	add_npc("pub_boy");
	add_npc("pub_girl");
	add_npc("pub_girl1");
	add_npc("helpnpc_jhlz");
	add_npc("helpnpc007");

	if (random(2)==0)
	{
	add_npc("pub_zhongxiaoer");
	add_npc("pub_girl");
	add_npc("pub_zhongsisao");
	}

	add_door("佛山南门", "佛山南门", "佛山");
	add_door("佛山西门", "佛山西门", "佛山");
	add_door("佛山东门", "佛山东门", "佛山");
	add_door("佛山北门", "佛山北门", "佛山");

	add_door("佛山英雄会馆", "佛山英雄会馆", "佛山");
	add_door("佛山烧饼油条铺", "佛山烧饼油条铺", "佛山");
	add_door("佛山英雄典当", "佛山英雄典当", "佛山");
	add_door("佛山北帝庙", "佛山北帝庙", "佛山");
	add_door("佛山英雄楼", "佛山英雄楼", "佛山");

	resettask();
//	resetrubbish();
	add("teapot/task",1);
	set("no_cast",  1);

};

void reset(/*CContainer * ob, LONG param1, LONG param2*/)
{
	CRresident::reset();

	if(random(5) == 0)
		resetrubbish();

	if (!query("teapot/task"))
		resettask();

/*<---------------Call for set task.
Reset all task. ----------------->*/
	add("teapot/task",1);
	if (query("teapot/task")==4)
		del("teapot/task");
}

void resettask()
{
		CRoom * room1;
		CContainer * task1;
		CRoom * room2;
		CContainer * task2;
		CRoom * room3;
		CContainer * task3;
		CRoom * room4;
		CContainer * task4;

	if (query("task1"))
	{
		task1=find_object(query("task1"));
		DESTRUCT_OB(task1, "task1");
		task2=find_object(query("task2"));
		DESTRUCT_OB(task2, "task2");
		task3=find_object(query("task3"));
		DESTRUCT_OB(task3, "task3");
		task4=find_object(query("task4"));
		DESTRUCT_OB(task4, "task4");
	}

	task1=load_item("lingpai");
	task1->set_name("红烧鸡翅","hongshao jichi");
	task1->set("long","一盘［凤七］的红烧鸡翅。 :9``");
	task1->set("is_task",1);
	task1->set("valued",(random(1500)+500));


	task2=load_item("lingpai");
	task2->set_name("弹珠","tangzhu");
	task2->set("long","一粒［欧阳山庄白老庄主］的弹珠。 ^^");
	task2->set("is_task",2);
	task2->set("valued",(random(1500)+500));

	task3=load_item("lingpai");
	task3->set_name("阴阳合和散","yinyang hehesan");
	task3->set("long","一包［何芳芳］的阴阳合和散。 :)...");
	task3->set("is_task",3);
	task3->set("valued",(random(1500)+500));

	task4=load_item("lingpai");
	task4->set_name("情书","qingshu");
	task4->set("long","一封不知道是［谁］的情书，上面写着：亲爱的蓝木美眉…… @@");
	task4->set("is_task",4);
	task4->set("valued",(random(2500)+1000));

	
	room1=load_room(global_room_name[random(MAX_ROOM_NUM)]);
	int i;
	i=random(MAX_ROOM_NUM*3);
	i=i/3;
	room2=load_room(global_room_name[i]);
	i=random(MAX_ROOM_NUM/3);
	i=i*3;
	room3=load_room(global_room_name[i]);
	i=random(MAX_ROOM_NUM*2);
	i=random(i);
	if (i>MAX_ROOM_NUM)
		i=i/2;
	room4=load_room(global_room_name[i]);

	task1->move(room1);
	task2->move(room2);
	task3->move(room3);
	task4->move(room4);

	set("task1r",room1->querystr("base_name"));
	set("task2r",room2->querystr("base_name"));
	set("task3r",room3->querystr("base_name"));
	set("task4r",room4->querystr("base_name"));

	set("task1",task1->object_id());
	set("task2",task2->object_id());
	set("task3",task3->object_id());
	set("task4",task4->object_id());

//	g_Channel.do_channel(&g_Channel, 0, "news", "最近又有不少人遗失物品，请大家注意……");

//	set("teapot/task",1);
}

void resetrubbish()
{
	CRoom * room1;
	CContainer * task1;

	static char xbe[16][20]={"小香蕉皮","小西瓜皮","小苹果核","小破木头","小烂梨子","小布片","小碎陶片","小空易拉罐","小冷却的杭州小龙包","小打破的玻璃","小作废的飞机票","小烧焦的地瓜饼","小碎唐三彩","小瓜子壳","小断掉的一晚十个郎","小刻坏的CD"};

	int i;
	int q;
	q=random(20) + 10;
	set("roundrubbish",q);
	for (i=1;i<q; i++)
	{
	task1=load_item("tuijianxin_1");
	task1->set_name(xbe[random(16)], "rubbish");
	task1->set("long","一堆垃圾。");
	task1->set("pub_rubbish",1);
	task1->set("unit","堆");	
	task1->set("valued",random(100)+1);
	task1->set("value", 0l);

	room1=load_room(global_room_name[random(MAX_ROOM_NUM)]);

	//char msg[255];
	//g_Channel.do_channel(&g_Channel, 0, "sys", snprintf(msg, 255, "一个垃圾从天而降，掉在%s。", room1->name(1) ));

	task1->move(room1);
	}

	//g_Channel.do_channel(&g_Channel, 0, "news", "本市垃圾正在增多……");

//	set("teapot/task",1);
}


RESIDENT_END;
