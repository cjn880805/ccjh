// lingboweibu.h �貨΢��

FORCE_BEGIN(CSlingboweibu);

virtual void create()
{
	set_name( "�貨΢��");
}

CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	static struct {
		char action[255];
		int dodge, lvl;
	}action[5] = {
		{"ֻ��$n��һ������һ��������׾ٵĶ��$N��һ�С�", 5, 0},
		{"����$n����һ�����Ӳ���˼��ĽǶ�ת���������ܿ���$N�Ĺ�����", 5, 30},
		{"Ȼ��$nȴ���˷��������²�����Ī�⣬��ʹ$N�Ĺ���ȫ����ա�", 10, 60},
		{"����$n����Ʈ������ǰ���󣬺�����ң���$N�޷����֡�", 15, 90},
		{"����$n������ת���Ų�΢�䣬�˾���������֮�⣬��������һ�С�", 25, 150},
	};

	int level = me->query_skill("lingboweibu", 1);
	for(int i=5; i>0; i--)
	{
		if(action[i - 1].lvl < level)
		{
			level = random(i);
			char msg[255];

			//�����ϱ�ڤ��,�ӱ�
			if(! DIFFERSTR(me->query_skill_mapped("force"), "beiming_shengong") && random(1 + me->query("mp")) > 1000)
			{
				m_actions.set("action", snprintf(msg, 255, "$HIB%s$COM", action[level].action) );
				m_actions.set("dodge", action[level].dodge * 3);			

				if(me->query_temp("apply/sub_mp")>0)	//���װ�����м���MP���ĵĵ���
					me->add("mp", -50*(100-me->query_temp("apply/sub_mp"))/100);
				else
					me->add("mp",-50);
				me->SendState(me);
			}
			else
			{
				m_actions.set("action", action[level].action);
				m_actions.set("dodge", action[level].dodge);			
			}

			break;
		}
	}
	
	return & m_actions;
};

virtual int valid_enable(string usage) { return usage=="dodge" ||  usage=="move"; }

virtual int valid_learn(CChar * me){return 1;}

virtual int practice_skill(CChar * me)
{
	if( me->query("hp") < 40 )
		return notify_fail("�������̫���ˣ��������貨΢����");
	me->receive_damage("hp", 30);
	return 1;
}

SKILL_END;
