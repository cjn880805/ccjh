//heishatan.h

//Sample for room: ��ɽ��ɳ̶
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_heishatan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ��ɳ̶");

	add_door("��ɽɽ��", "��ɽɽ��", "��ɽ��ɳ̶");

    set("long","��ɳ̶�ֳƺ���̶������ף�ˮɫ�Ժڣ��ٲ�������ˮ�к��ݹ���ĭ���࣬���Ŀɲ���ʯ���� '��������' ���־���Ϊ���λ�����٥�������ݽ����壬һ��������" );
    

/*****************************************************
        set("exits", ([ 
            "up"  : __DIR__"shanjian",
        ]));
********************************************/
};


ROOM_END;
