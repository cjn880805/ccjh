//yuzhengong.h

//Sample for room: ���湬
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRWuDang_yuzhengong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���湬");

	add_npc("wudang_zhixiang");	
	
	add_door("�䵱������", "�䵱������", "�䵱���湬");
	add_door("�䵱����", "�䵱����", "�䵱���湬");

	set("long","�����ǽ����䵱ɽ�ĵ�һ���������湬�����ޱȣ�����ǧ��ʳ�ޣ��ǽ���͵�һ��Ъ�Ŵ��������������ڴ˽�����������˹��й������������������������˱չ��Ѿã����˲�֪���Ƿ������˼䣬��䴫˵���ѵõ����ţ�����Ĥ�ݡ�");

/*****************************************************
      set("objects", ([
           CLASS_D("wudang") +"/zhixiang": 1,
      ]));
      set("outdoors", "wudang");
      set("exits",([ 
          "northdown": __DIR__"shijie1",
          "southup"  : __DIR__"wdbl",
      ]));
*****************************************************/
};


ROOM_END;
