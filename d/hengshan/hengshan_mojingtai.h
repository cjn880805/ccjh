//mojingtai.h

//Sample for room: ��ɽĥ��̨
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_mojingtai);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽĥ��̨");


	add_door("��ɽɽ·6", "��ɽɽ·6", "��ɽĥ��̨");
	add_door("��ɽɽ·8", "��ɽɽ·8", "��ɽĥ��̨");
	add_door("��ɽɽ·7", "��ɽɽ·7", "��ɽĥ��̨");

    set("long","ĥ��̨λ���������£����ɽͤһ�����ڡ�̨ǰ���·ת��̨�Թ��ɲԴ䣬�������ġ��ഫ�������ڻ����ڴ����� '������' ����̨��ɮ����������ĥ�����Ƿ����ڵ�һ����̨��������� 'ĥ��̨֮��' �Ǻ�ɽ���ľ�֮һ��" );
    

/*****************************************************
        set("exits", ([ 
           "southdown"  : __DIR__"shanlu8",
           "westup"     : __DIR__"shanlu7",
           "northup"    : __DIR__"shanlu6",
        ]));
********************************************/
};


ROOM_END;
