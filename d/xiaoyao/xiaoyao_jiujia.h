//jiujia.h

//Sample for room: �Ƽ�
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRXiaoYao_jiujia);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ң�־Ƽ�");

	add_npc("pub_xiaoer2");
	add_item("shaguan");
	add_item("ciwan");

	add_door("��ң��С��3", "��ң��С��3", "��ң�־Ƽ�");

	set("long", "�����������е�һ��СС�ľƼң��ط���Ȼ���󣬵���Ҳ�в�����ң�ɵĵ��ӹ������������ҵ���ζ����Դ�ˣ����ſɿڵķ��ˣ����̲�סҲ��� (order)һ���ˡ�");
	
	set("ricewater", 5);

/*****************************************************
	set("exits",([
		"north" : __DIR__"xiaodao2",
	]));
********************************************/
};


ROOM_END;
