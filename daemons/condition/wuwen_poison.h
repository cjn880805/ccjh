CONDITION_BEGIN(CCwuwen_poison);

virtual int update_condition(CChar *me, LONG & duration)
{
	char msg[255];

	if( duration < 1 ) return 0;

	if(! living(me)) 
	{
		message_vision("$Nʹ��غ���һ����", me);
	}
	else 
	{
		tell_object(me, "��Ȼһ��̹ǵľ�ʹϮ�������е�����צ�˷����ˣ�");
		tell_room(me->environment(), snprintf(msg, 255, "%sʹ�಻���Ĵ�У������ɵ��书�����޵С�", me->name()), me);
	}
    
	me->receive_wound("hp",1 + random(4));
    duration --;
      
	if ( me->querymap_temp("powerup") )		//����POWERUP
	{ 
		me->remove_call_out(CSkill::remove_powerup);
		CSkill::remove_powerup(me, 1, 0);
	}

	return CND_CONTINUE;
}

CONDITION_END;