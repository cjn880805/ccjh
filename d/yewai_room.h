#define YEWAIROOM_BEGIN(room_name)	class room_name : public CRyewai_room	{	public:	room_name(){};	virtual ~room_name(){};
#define YEWAIROOM_END		}	

//XuNing 2001-08-31

ROOM_BEGIN(CRyewai_room);

virtual int valid_leave(CChar * me, const char * dir)
{
	if(me->query("level")<80)
	{
		tell_object(me,"����Ŀǰ���������ǲ�Ҫ��ȥ�ɣ���ȥ�ɣ�");
		me->move(load_room("��ɽ������"));
		return 0;
	}
	CDoor *d;
	UINT n;
	
	if((d = PresentDoor(dir)) == 0)return 1;
	
	if(((n = me->query_temp("mapnum")) == 0 || me->query_temp("firstmap") == 1) && !strcmp(me->querystr_temp("todir"), d->querystr("id")))
	{
		CRoom * r = load_room(me->querystr_temp("frommap"));		//��ȡ��ʱ�ĵ�ͼ
		if(! r) return 0;
		
		me->set_temp("init_door", me->querystr_temp("fromdir"));
		if(me->move(r))
		{
			me->delete_temp("frommap");
			me->delete_temp("fromdir");
			me->delete_temp("todir");
			me->delete_temp("mapnum");
			me->delete_temp("init_door");
			return 2;						//�ƶ�ʧ���Ҳ�����ʧ����Ϣ
		}
		me->delete_temp("init_door");
	}
	else if(n > 0)
	{
		me->set_temp("mapnum", --n);
	}
	
	me->delete_temp("firstmap");
	
	return 1;
}

virtual void ChangeRoom(CContainer * me)
{
/*	tell_object(me, "Զ����Լ������ħ���Ŀ�Ц��", "tell");

	switch (random(4))//�Ƿ񴥷�
	{
	case 0://�����¼�
		message_vision ("$N�������ܿռ����ڷ�����䣬����׽���������ﲻ�ԡ�", me);						

		switch (random(9))
		{
		case 0:	//�����¼�1�����棺ǿ�ҵ��˺�
			message_vision ("$RED��Ȼ��ɫһ�������ű�죬Ȼ����������½���������һ�Ż���$Nӭ��������$COM", me);						
			return 0;

		case 1:	//�����¼�2����ˮ���������˺�
			message_vision ("$RED����һƬ���֮���������Ķ�ˮ���ϴ������������������ң��ٽ����ǣ��ۼ�Ҫ����$N��$COM", me);						
			return 0;

		case 2:	//�����¼�3�����飺�͵��˺����е�æ��
			message_vision ("$RED$N�о���׹����,�����д����ӿ��з��������ܱ������߰������죬��������ޱ���$N������", me);						
			return 0;

		case 3:	//�����¼�4�����ͣ�ǿ���˺����͵�æ��
			message_vision ("���ܷ���������ɱ�����죬$N��������һ�����Ǵ�ս���������ͷɽ����ۿ��Լ����ҡ�", me);						
			return 0;

		case 4:	//�����¼�5�����磺���ͷ�����
			message_vision ("$Nֻ�����ڹ���������������������������������Ҫ��������", me);						
			return 0;

		case 5:	//�����¼�6�����磺��仯��Χ���˺����е�æ�ҡ�
			message_vision ("��Ȼ��ɫһ���������������ƶ�����$N�ŵñ�ס��߿�ľ���ּ�һ���������ľ������", me);						
			return 0;

		case 6:	//�����¼�7���������͵��˺����ߵ�æ��
			message_vision ("$N�����Լ�������һ���������У�����������ɢ�������������κζ����ˡ�", me);						
			return 0;

  		case 7:	//�����¼�8��ʯ�飺�е��˺�
			message_vision ("$N�����Լ�������һ��Ͽ�ȣ����治�����¾޴����ʯ��һ��С�ľͻᱻ���С�", me);						
			return 0;

  		case 8:	//�����¼�9�����ѣ��е��˺����͵�æ��
			message_vision ("������ض���ǿ�ҵ����У�$Nվ�����ȣ��ۿ������ѷ�֮�С�", me);						
			return 0;

		case 9://�����¼�10��ת�Ƶ���������
			message_vision ("$N����������ת���Լ�������һ��Ī�������Ť���ռ�֮�С�", me);
			return 0;
		}

	case 1://δ����1
		message_vision ("ֻ������Զ�ĵط�Ľ����Ө������Ц��$N���м�����У�����������Ұ��", me);
		return 0;
		
	case 2://δ����2
		message_vision ("Ľ����Ө���յĵ�Ц����Ȼ���ˣ��Ͳ�Ҫ���ų�ȥ�ˡ�", me);
		return 0;
		
	case 3://δ����3
		message_vision ("Ľ����Ө�ٺٵ�Ц�ţ��㲻�Ǻ�ţXô�����������ﻹװ��װӢ�ۡ�", me);
		return 0;
		
	case 3://δ����4
		message_vision ("Ľ����Ө���������㣺�����������϶��кܶ౦����������ɱ�˶�����������ˡ���", me);
		return 0;
	}
	return 0;
*/	
	CRoom::ChangeRoom(me);
}

ROOM_END;