//qhpo.h
//Sample for room:  ÷ׯ�滱��
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRMeiZhuang_qhpo);

virtual void create()			//Call it when Room Create
{
	//set name of our room

	set_name( "÷ׯ�滱��");
	add_item("meishu");
	add_item("meishu");

	add_door("÷ׯ��ľ԰", "÷ׯ��ľ԰", "÷ׯ�滱��");
	add_door("÷ׯС·", "÷ׯС·", "÷ׯ�滱��");
	set("long", "��������滱���ˣ��������Ŵ��СС��ǧ��ٹֵĻ������еĻ���һֱ���죬�е����������ƣ������������ԼԼ����һ������������������ޣ��������֡� " );

};

ROOM_END;
