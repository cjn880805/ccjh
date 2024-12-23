CONDITION_BEGIN(CCdsy_poison);

virtual int update_condition(CChar *me, LONG & duration)
{
	if( duration < 1 ) return 0;
	if( ! me->Query(IS_LIVING) ) 
	{
		message_vision("$HIG$Nü����б����ͷ�������������˳�����һ��������ĭ˳����������ʡ�\n", me);
	}
	else if(me->query("eff_hp") > me->query("max_hp")/2) 
	{
		tell_object(me, "$CYN��о�����֮��������ƣ�ȫ����������ɢ�ܡ�\n" );
	}
	else if(me->query("eff_hp") > me->query("max_hp")/4) 
	{
		tell_object(me, "$CYN������֮����ʼ���÷����������˼�ֻ��Ӭ����֫��������������\n");
	}
	else
	{
		tell_object(me, "$CYN�ƶ��Ѿ�������������������������ʧ���е�������������޵�����������\n" );
		message_vision("$HIG$NͻȻ�������Ƶ�̱���ڵأ�ȫ����ŧ������һ����Ķ����ͷ��һ���������䣬���Ʈɢ��\n", me);
	}
	
	me->receive_wound("hp", 25 + random(30));
	duration --;
	
	if ( me->querymap_temp("powerup") )		//����POWERUP
	{ 
		me->remove_call_out(CSkill::remove_powerup);
		CSkill::remove_powerup(me, 1, 0);
	}
	
	if( duration < 1) return 0;
	return CND_CONTINUE;
}

CONDITION_END;