//yunu.h

//Sample for room: ��ɽ��Ů��
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRHuaShan_yunu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ��Ů��");
	
	add_npc("huashan_laodenuo");       //add by zdn 2001-07-20


	add_door("��ɽ������", "��ɽ������", "��ɽ��Ů��");
	add_door("��ɽ��Ů��", "��ɽ��Ů��", "��ɽ��Ů��");
	add_door("��ɽ���䳡", "��ɽ���䳡", "��ɽ��Ů��");
	add_door("��ɽСɽ·", "��ɽСɽ·", "��ɽ��Ů��");
	add_door("��ɽ��Ů��ɽ·", "��ɽ��Ů��ɽ·", "��ɽ��Ů��");

	set("long", "�����ǻ�ɽ���з壬��Ů�塣��˵����ʱ��ʿ��ʷ�ƴ�����������������¹�Ů��Ū��İ�Ľ�������˹�͢�������ʷ�������ӣ��ʳ���Ů�塣���������Ϊƽ�������������ķ���վ��������Ϻպ������Ļ�ɽ���ɾ��ڴ˴�����������СС������Ǿ�����Ů���ˡ�����ϡϡ������ʮ���䷿�ӣ��ǻ�ɽ�ɵĵط��������ο���ñ�������ȥ��");  
 
/*****************************************************
        set("exits", ([  
            "westdown"  : __DIR__"zhenyue",
            "west"      : __DIR__"yunuci",
            "north"     : __DIR__"square",
            "southdown" : __DIR__"yunupath1",
            "northeast" : __DIR__"xiaolu1",
       ]));
       set("objects", ([
            __DIR__"npc/yue-lingshan" : 1,
       ]));
********************************************/
};


ROOM_END;
