//jigaoming.h



//Sample for room: ��ɽ������̨

//coded by zouwenbin

//data: 2000-11-29



ROOM_BEGIN(CRHengShan_jigaoming);



virtual void create()			//Call it when Room Create

{

	//set name of our room

	set_name( "��ɽ������̨");


	add_door("��ɽ������", "��ɽ������", "��ɽ������̨");




    set("long","�����Ǹ�������ߴ����������������� '������' ���������ڴˣ��⼴���༫�� (���޼�����) ����⼫�� (����������) �������������ϵģ���Ի������̨��" );

    



/*****************************************************

        set("exits", ([ 

           "northdown"  : __DIR__"sansheng",

        ]));

********************************************/

};





ROOM_END;
