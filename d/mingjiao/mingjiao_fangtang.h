//fangtang.h



//Sample for room: ���̷���

//coded by zouwenbin

//data: 2000-11-16



ROOM_BEGIN(CRMingJiao_fangtang);



virtual void create()			//Call it when Room Create

{

	//set name of our room

	set_name( "���̷���");



	CBox * box = Add_Box();
	box->add_object("jiuping", 1);	
	box->set_name( "����");	

	add_door("���̹㳡", "���̹㳡", "���̷���");



	set("long", "����������̵ķ��á������˳����Ĳ����ͳ��ʣ���λ�������������æµ�Ų��á����ϰ��˼��趹��������������Լ����㣬���⣬�����Ƶ���ζʳ�����ߵ�����ͨ��㳡��");



/*****************************************************

      set("exits",([ 

          "east" : __DIR__"square", 

      ]));



      set("objects",([

          "/d/hangzhou/npc/obj/jiuping": 1,

           names[random(sizeof(names))]: 1,

           names[random(sizeof(names))]: 1,

           names[random(sizeof(names))]: 1,

           names[random(sizeof(names))]: 1,

           names[random(sizeof(names))]: 1,

      ]));

//      

********************************************/

};





ROOM_END;
