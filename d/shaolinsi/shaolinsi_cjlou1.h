//cjlou1.h

//Sample for room: �ؾ����¥
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_cjlou1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ؾ����¥");

	CBox * box = Add_Box();
	box->add_object("wuji1", 1);	
	box->set_name( "����");
		
	CBox * box1 = Add_Box();
	box1->add_object("wuji2", 1);	
	box1->set_name( "����");
		
	CBox * box2 = Add_Box();
	box2->add_object("wuji3", 1);	
	box2->set_name( "����");
		
	CBox * box3 = Add_Box();
	box3->add_object("yijinjing", 1);	
	box3->set_name( "����");	

	add_door("�����²ؾ���һ¥", "�����²ؾ���һ¥", "�����²ؾ����¥");

	set("long", "ǧ������������ִ��ԭ����֮ţ�����Դ�Ħ�������£������˲ı����������в��ٸ�ɮ�������棬�㼯�����ճ��������µ�������ʮ�����ա����־����������ڴˡ���¥���濪����ȷ��ͨ�硣�м����������Ŵ���ܡ���������а������Թ��Ķ�����λ��ɮ��ִ�������ڱ�Ŀ��˼��" );

/*****************************************************
	set("exits", ([
		"down" : __DIR__"cjlou",
	]));
	set("objects",([
		CLASS_D("shaolin") + "/hui-zhen" : 1,
		"/clone/book/yijinjing" : 1,
		"/clone/book/wuji1" : 1,
		"/clone/book/wuji2" : 1,
		"/clone/book/wuji3" : 1,
	]));
//	
********************************************/
};


ROOM_END;
