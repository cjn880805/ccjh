//sansheng.h



//Sample for room: ��ɽ������

//coded by zouwenbin

//data: 2000-11-29



ROOM_BEGIN(CRHengShan_sansheng);



virtual void create()			//Call it when Room Create

{

	//set name of our room

	set_name( "��ɽ������");


	add_door("��ɽ������", "��ɽ������", "��ɽ������");

	add_door("��ɽ������̨", "��ɽ������̨", "��ɽ������");



    set("long","�������Ǹ����¿�ɽ��ʦ��˼��Ǵ�����˵��˼��ʦ���������������ʳ�����������Զ���п����ӣ���˵���ܽ��ڻ�˼��ʦ������ǧ�꣬��ͤͤ���ǣ�������ԡ�" );

    



/*****************************************************

        set("exits", ([ 

           "southup"   : __DIR__"jigaoming",

           "eastdown"  : __DIR__"fuyansi",

        ]));

********************************************/

};





ROOM_END;
