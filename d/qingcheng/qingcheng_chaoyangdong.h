//chaoyangdong.h

//Sample for room: ��ǳ�����
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRQingCheng_chaoyangdong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ǳ�����");

	//add npcs into the room
	add_npc("qingcheng_hai");/////////////////////////

	add_door("�����ʦ��", "�����ʦ��", "��ǳ�����");
	add_door("�������ŵ�", "�������ŵ�", "��ǳ�����");

	set("long","����������������������ɣ��ഫ����������Ϣ��������Ҳ�ǹ��պ�ȥ�������Ŷ����ٹ���ҫ��������ָ���ն�����ϼ��͸�������䵽���ڣ�һƬ譲�Ѥ���ľ�ɫ��");

/*****************************************************
        set("outdoors","qingcheng");
	set("exits", ([
		"westdown"  : __DIR__"zushidian",
		"northup"   : __DIR__"sanwanjiudao",
	]));
	set("objects", ([
		__DIR__"npc/hong" : 1,
	]));
*****************************************************/
};


ROOM_END;
