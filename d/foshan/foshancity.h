
RESIDENT_BEGIN(CRfoshancity);

virtual void create()		
{

	set_name( "��ɽ");

	set("resident", "��ɽ");
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

	add_door("��ɽ����", "��ɽ����", "��ɽ");
	add_door("��ɽ����", "��ɽ����", "��ɽ");
	add_door("��ɽ����", "��ɽ����", "��ɽ");
	add_door("��ɽ����", "��ɽ����", "��ɽ");

	add_door("��ɽӢ�ۻ��", "��ɽӢ�ۻ��", "��ɽ");
	add_door("��ɽ�ձ�������", "��ɽ�ձ�������", "��ɽ");
	add_door("��ɽӢ�۵䵱", "��ɽӢ�۵䵱", "��ɽ");
	add_door("��ɽ������", "��ɽ������", "��ɽ");
	add_door("��ɽӢ��¥", "��ɽӢ��¥", "��ɽ");

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
	task1->set_name("���ռ���","hongshao jichi");
	task1->set("long","һ�̣۷��ߣݵĺ��ռ��ᡣ :9``");
	task1->set("is_task",1);
	task1->set("valued",(random(1500)+500));


	task2=load_item("lingpai");
	task2->set_name("����","tangzhu");
	task2->set("long","һ����ŷ��ɽׯ����ׯ���ݵĵ��顣 ^^");
	task2->set("is_task",2);
	task2->set("valued",(random(1500)+500));

	task3=load_item("lingpai");
	task3->set_name("�����Ϻ�ɢ","yinyang hehesan");
	task3->set("long","һ���ۺη����ݵ������Ϻ�ɢ�� :)...");
	task3->set("is_task",3);
	task3->set("valued",(random(1500)+500));

	task4=load_item("lingpai");
	task4->set_name("����","qingshu");
	task4->set("long","һ�ⲻ֪���ǣ�˭�ݵ����飬����д�ţ��װ�����ľ��ü���� @@");
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

//	g_Channel.do_channel(&g_Channel, 0, "news", "������в�������ʧ��Ʒ������ע�⡭��");

//	set("teapot/task",1);
}

void resetrubbish()
{
	CRoom * room1;
	CContainer * task1;

	static char xbe[16][20]={"С�㽶Ƥ","С����Ƥ","Сƻ����","С��ľͷ","С������","С��Ƭ","С����Ƭ","С��������","С��ȴ�ĺ���С����","С���ƵĲ���","С���ϵķɻ�Ʊ","С�ս��ĵعϱ�","С��������","С���ӿ�","С�ϵ���һ��ʮ����","С�̻���CD"};

	int i;
	int q;
	q=random(20) + 10;
	set("roundrubbish",q);
	for (i=1;i<q; i++)
	{
	task1=load_item("tuijianxin_1");
	task1->set_name(xbe[random(16)], "rubbish");
	task1->set("long","һ��������");
	task1->set("pub_rubbish",1);
	task1->set("unit","��");	
	task1->set("valued",random(100)+1);
	task1->set("value", 0l);

	room1=load_room(global_room_name[random(MAX_ROOM_NUM)]);

	//char msg[255];
	//g_Channel.do_channel(&g_Channel, 0, "sys", snprintf(msg, 255, "һ�������������������%s��", room1->name(1) ));

	task1->move(room1);
	}

	//g_Channel.do_channel(&g_Channel, 0, "news", "���������������࡭��");

//	set("teapot/task",1);
}


RESIDENT_END;
