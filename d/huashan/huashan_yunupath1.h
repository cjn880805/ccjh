//yunupath1.h

//Sample for room: ��ɽ��Ů��ɽ·1
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRHuaShan_yunupath1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ��Ů��ɽ·");
	
	add_npc("pub_daoke");          //add by zdn 2001-07-17

	add_door("��ɽ��Ů��", "��ɽ��Ů��", "��ɽ��Ů��ɽ·");
	add_door("��ɽ˼����", "��ɽ˼����", "��ɽ��Ů��ɽ·");

	set("long", "��������Ů���ɽ��һ��ɽ·��·�߳����˴���ÿ��΢���������Ҷ��ɳɳ���죬�Ե÷�����ľ���");  
    
 
/*****************************************************
      set("exits",([  
          "southup"  : __DIR__"yunupath2",
          "northup"  : __DIR__"yunu",
      ]));
********************************************/
};


ROOM_END;
