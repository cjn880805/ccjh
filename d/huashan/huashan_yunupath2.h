//yunupath2.h

//Sample for room: ��ɽ��Ů��ɽ·2
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRHuaShan_yunupath2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ��Ů��ɽ·2");
	
	add_npc("pub_jianke");            //add by zdn 20017-07-17


	add_door("��ɽ��Ů��ɽ·1", "��ɽ��Ů��ɽ·1", "��ɽ��Ů��ɽ·2");
	add_door("��ɽ˼����", "��ɽ˼����", "��ɽ��Ů��ɽ·2");

	set("long", "��������Ů���ɽ��һ��ɽ·��·�߳����˴���ÿ��΢���������Ҷ��ɳɳ���죬�Ե÷�����ľ���");  
    
 
/*****************************************************
      set("outdoors", "xx");
      set("exits",([  
          "southup"   : __DIR__"siguoya",
          "northdown" : __DIR__"yunupath1",
      ]));
********************************************/
};


ROOM_END;
