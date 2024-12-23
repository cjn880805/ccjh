//huiguan.h

//Sample for room: Ӣ�ۻ��
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRFoShan_huiguan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "Ӣ�ۻ��");

	//add npcs into the room
	add_npc("pub_fengzaiming");
	
	add_door("��ɽ", "��ɽ", "��ɽӢ�ۻ��");

	set("long", "Ӣ�ۻ��Ҳ�Ƿ���ү�ļ�ҵ���������Ǯ�ģ���������������ͷ�ġ��ĳ���Χ�ź�ѹѹ��һȺ�ˣ�������(gamble)����Ѻ��С���ű�����һ������(paizi)��" );
	set("no_fight", "1");
/*****************************************************
	set("objects", ([
	   __DIR__"npc/fengyiming": 1,
	]));
        set("item_desc", ([
                "paizi" :
"����С���ķ���\n"
"��������ɫ������һֻ���ɫ�ӵ����ܺͣ�\n"
"       �� �� ʮ Ϊ��С����\n"
"       ʮһ �� ʮ�� Ϊ���󡹣�\n"
"       ����ɫ�ӵ�����ͬ�����Сͨ�ԡ�\n"
"\n������󣬿�С��С��һ��һ��\n"
"\n���ĳ����ܸ��ֻ��Ҽ�����ĵ���Ϊ��ע��\n"
"\n��עΪ��ʮ��һǧ��١�\n",
        ]));
	set("exits",([ 
	    "north" : __DIR__"street2",
	]));

********************************************/
};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}
ROOM_END;
