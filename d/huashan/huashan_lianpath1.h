//lianpath1.h

//Sample for room: ��ɽ������С·
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRHuaShan_lianpath1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ������С·");


	add_door("��ɽ������", "��ɽ������", "��ɽ������С·");
	add_door("��ɽ������ɽ��", "��ɽ������ɽ��", "��ɽ������С·");

	set("long", "С·ͨ�������壬��Χ�������ģ�΢�Ų��������������Ĺȣ����˵�����");  
    
 
/*****************************************************
      set("exits",([  
          "westup"   : __DIR__"chengxiang",
          "eastdown" : __DIR__"lianpath1",
      ]));
********************************************/
};


ROOM_END;
