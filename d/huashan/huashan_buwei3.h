//buwei3.h

//Sample for room: ��ɽƫ��
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRHuaShan_buwei3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽƫ��");

	add_npc("pub_qiufengcheng");
	add_door("��ɽ������Ϊ��", "��ɽ������Ϊ��", "��ɽƫ��");

	set("long", "ƫ���﹩���Ż�ɽ������ʦ����λ�������񰸵�ǽ���ǻ�ɽ�ɿ�ɽ��ʦ����ʦ�Ļ��󡣻��������������ǳ�����������¯������������㣬��������������ɢ����һ��̴��ζ������������ͨ�����������.");  
    
    set("valid_startroom","1");
 
/*****************************************************
        set("exits", ([  
            "west" : __DIR__"buwei1",
	]));
********************************************/
};


ROOM_END;
