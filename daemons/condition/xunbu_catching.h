//����Ѳ��׷ɱ
//lanwood 2001-04-14

CONDITION_BEGIN(CCxunbu_catching);

int update_condition(CChar *me, LONG & duration)
{
	//�ж��Ƿ���ڣ���������¼
	/*
	if(current_time > me->query("kill/free"))	
	{
		me->del("kill/guilt");
		return 0;
	}
	*/
	if( me->query("kill/guilt") < 150 ) return 0;	

	if(random(5)) return CND_CONTINUE;

		//1���ж��Ƿ��ڳ��С�
		CContainer * env = me->environment();
		
		if(! env) return CND_CONTINUE;
		if(! env->query("city") && duration < 5) return CND_CONTINUE;
		
		//2���жϳ������Ƿ��Ѿ���Ѳ����
		CNnpcmirror * xunbu;

		xunbu = (CNnpcmirror *)env->PresentName("monster_xunbu", CChar::IS_NPC);

		if(! xunbu )
		{
			xunbu = (CNnpcmirror *)load_npc("monster_xunbu");
			xunbu->move(env);			
		}	
		
		message_vision("ͻȻһ����Ӱ������$N����$n��ǰ���ȵ�����Щ���һ�ȥ����", xunbu, me);
		message_vision("$Nüͷһ�壬���һ������������ʲô������", me);
		((CNnpcmirror *)xunbu)->catch_ob(me);		
		
	return CND_CONTINUE;
}



CONDITION_END;