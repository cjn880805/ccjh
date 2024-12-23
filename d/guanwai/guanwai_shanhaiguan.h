//shanhaiguan.h

//Sample for room: ɽ����
//coded by zouwenbin
//data: 2000-12-1

RESIDENT_BEGIN(CRGuanWai_shanhaiguan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ɽ����");

	set("resident", "ɽ����");

	//add npcs into the room
	add_npc("pub_wujiang");
	add_npc("pub_bing");
	add_npc("pub_bing");
	add_npc("pub_ouyangbu");
	add_npc("pub_ouyangzhan");
	
	add_door("��������ͷ", "��������ͷ", "����ɽ����");
	add_door("����ٵ�", "����ٵ�", "����ɽ����");

    set("long","����������ﳤ��������Ҫ�ؿ�--ɽ���ء����������Ҫ���Թž��ǹ���ͨ����ԭ�ıؾ�֮�ء�վ�ڹ�¥�ϱ�������ɽ���ű������̨������Ŀ�����س���Զ����ֱ���뺣������ͷ��ϡ�ɼ�����¥��¥��������һ��޷�����(bian)��" );
	

/*****************************************************
	set("exits", ([
		"northeast" : __DIR__"road1",
		"southeast" : __DIR__"laolongtou",
	]));
	set("objects", ([
		"/d/city/npc/wujiang" : 1,
		"/d/city/npc/bing"    : 2,
	]));
	set("item_desc",([
		"bian" : 
"
    ��������������������������������������
    ��������������������������������������
    ������������  ��  ��  һ  ��  ��������
    ��������������������������������������
    ��������������������������������������\n",
	]));
********************************************/
};


RESIDENT_END;
