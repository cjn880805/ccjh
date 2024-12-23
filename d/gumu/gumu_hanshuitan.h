//hanshuitan.h

//Sample for room: ��Ĺ��ˮ̶
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRGuMu_hanshuitan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��Ĺ��ˮ̶");


	add_door("��Ĺ�ݵ�2", "��Ĺ�ݵ�2", "��Ĺ��ˮ̶");

    set("long","�����ǲݵصı�Ե������Ѿ���ϡ���ˣ���Ȼ��һ��������صطɹ�Ѱ��ʳ������ǰ��һ���岨�����Ĵ�ˮ̶ (tan)��ˮ���壬��Լ���Լ���ˮ�׵Ĺ�ʯ��ᾣ�һ������ٿ�ش�ˮ���ι����ֲ�֪���㵽�Ŀ�ʯͷ�������ȥ�ˡ�����ӳ���£�ˮ�淺����һ����ɫ�ʺ磬����������������������" );

};

virtual int do_look(CChar * me)
{

	say("�����ǲݵصı�Ե������Ѿ���ϡ���ˣ���Ȼ��һ��������صطɹ�Ѱ��ʳ������ǰ��һ���岨�����Ĵ�ˮ̶ (tan)��ˮ���壬��Լ���Լ���ˮ�׵Ĺ�ʯ��ᾣ�һ������ٿ�ش�ˮ���ι����ֲ�֪���㵽�Ŀ�ʯͷ�������ȥ�ˡ�����ӳ���£�ˮ�淺����һ����ɫ�ʺ磬����������������������" ,me);
	if(me->query_temp("gumu/lin"))
	{
		say("һ�ں����ˮ̶����֪���ɲ�����Ǳ(qian)�µ���ˮ������ȥ��", me);
		AddMenuItem("����", "$0qian", me);
		AddMenuItem("����", "", me);
		
	}
	SendMenu(me);
	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg, char * tar)
{
	if(me->query_temp("gumu/lin")&&strcmp(comm, "qian") == 0)
	{
		return do_qian(me);
	}
	return 0;
}

int do_qian(CChar * me)
{
	
	message_vision ("$N���������һ��������ס������һ����������ˮ�С�ֻ��ˮ������֮�䣬$NǱ���˺�ˮ̶�ף�", me);
	message_vision ("Ҳ��֪$N���˶�ã�����$N�ĺ����𽥼��ٵ�ʱ����Ȼ��$N������ǰһ�����ƺ�ǰ�����˾�ͷ��", me);
	message_vision ("$N����ƣ�������������˰���Ĩ��Ĩ���ϵ�ˮ�飬��ϸ��ʼ��������Χ������", me);
	me->start_busy(5);
	if(random(me->query("age")+me->query("per"))>58)
	{
		me->delete_temp("gumu/lin");
		me->set_temp("gumu/tan",1);
		me->move(load_room("����ɽ̫�ҳ�"));
	}
	else
		me->move(load_room("����ɽ����̶"));

	return 1;
}
ROOM_END;




