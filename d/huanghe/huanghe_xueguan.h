//xueguan.h

//Sample for room: �ƺ�ѧ��
//coded by zouwenbin
//data: 2000-11-18

CHANGAN_BEGIN(CRHuangHe_xueguan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ƺ�ѧ��");

	//add npcs into the room
	add_npc("pub_xiucai");

	add_door("�ƺӹ���", "�ƺӹ���", "�ƺ�ѧ��");

	set("long","һ���ª��˽�ӣ��ıڽԿգ������а�����ѧ�����Լ�����̧���ķ��������ʡ�һ���鰸�������ӵ�һͷ�����ϰ��ż��������˵ġ����־��������ټ��ա���һ�ѽ�ߡ���ʥ��ʦ���Ϸ��ӵ�ʯ����Ƭ�����������鰸�����档");

/*****************************************************
	set("exits", ([
		"south"    : __DIR__"gulang",
	]));
	set("objects", ([
		__DIR__"npc/xiucai" : 1,
	]));
//	
********************************************/
};


CHANGAN_END;
