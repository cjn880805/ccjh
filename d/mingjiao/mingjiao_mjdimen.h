//mjdimen.h

//Sample for room: ������
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRMingJiao_mjdimen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������");


	add_door("������ʯ��4", "������ʯ��4", "���̵�����");
	add_door("����Ů��", "���̵���Ů��", "���̵�����");

	set("long", "ǰ��������̵ġ������š��ˣ�������������Ů���������ĵط������ſڿ���ȥ������Ӱ�����˴´¡����ǽ�����Ů��ȴҲ��������������롣�ſڻ�����һ��ľ��(mu pai)��" );
	
 
/*****************************************************
    set("exits", ([
        "enter" : __DIR__"nushe",
        "southwest" : __DIR__"mjdimen",
    ]));

   set("outdoors", "mingjiao");
   set("item_desc",(["mu pai" : (: look_pai :),]));
string look_pai()
{
	return
	"\n"
	"������������������������������������\n"
	"��                                ��\n"
	"��  �ô�Ů���ߣ�Ͷ���ˮ��̶�ܷ�����\n"
	"��                                ��\n"
    "��         ��������������ǫ ��    ��\n"
	"��                                ��\n"
	"������������������������������������\n";

}

********************************************/
};


ROOM_END;
