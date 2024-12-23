
// wuyun_jianfa.h �������ҽ�
//code by Fisho
//date : 2000-12-07

SKILL_BEGIN(CSwuyun_jianfa);

virtual void create()
{
	set_name( "�������ҽ�");
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "wuzheng_xinfa") || EQUALSTR(arg, "xuantian_shengong"))
		return 1;

	return notify_fail("�������ҽ������������񹦻������ķ����ʹ�á�");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  force,dodge,damage,lvl;
		char damage_type[5];
	}action[] = {
		{"$N��Сָ�ᵯ��һ�С����ϡ���Ȼ����$n�ĺ���", 120, 20, 60,0 ,"����",},
		{"$N��������ָ�������޵�һ���������Ҳ���һ����[����]�ѽ�$n����", 140, 15, 70, 0,"����",},
		{"$N��ָ���ӣ�һʽ[����]���εĴ���$n������", 170, 15, 80, 9,"����",},
		{"$N�����н���ɨ��ͬʱ�������������Ƶļ���������һ��[֧��]", 190, 10, 90, 19,"����",},
		{"$Nʹ�������ϡ��������������ߣ���ͬ��������������������$n��$l",240 ,10 ,100 ,29 ,"����",},
	};
	
	int level = 0;
	
	for(int i=5; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("wuyun_jianfa", 1))
		{
			level = random(i);
			CContainer * weapon;
			weapon = me->query_weapon();
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
			if (weapon->query("mindtwist"))
			{
				m_actions.set("action", action[level].action);
			//	m_actions.set("force", action[level].force * weapon->query("mindtwist")/1000);
				m_actions.set("dodge", action[level].dodge * weapon->query("mindtwist")/1000);
				m_actions.set("damage", action[level].damage * weapon->query("mindtwist")/1000);
			}
			break;
		}
	}
	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "sword") || (usage == "parry");
}

virtual int valid_learn(CChar * me)
{
	if ( me->query("max_mp") < 100)
		return notify_fail("�������������");
	if ( me->query_skill("sword", 1) < 20)
		return notify_fail("��Ľ������費�㡣");
	if ( me->query_skill("wuzheng_xinfa", 1) < 30
		&& me->query_skill("xuantian_shengong") < 30)
		return notify_fail("��������񹦻������ķ����̫ǳ��");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;
	
	if (! (weapon = me->query_weapon())
        ||  DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("��ʹ�õ��������ԡ�");
	if ( me->query("hp") < 50)
		return notify_fail("��������������������ҽ���");
	me->receive_damage("hp", 30);
	return 1;
	
}
/***********
return __DIR__"wuyun-jianfa/" + action;

  //perform 
  virtual int Cast(string magic, CChar * me, CContainer *  ob = NULL)
  {
  string msg;
  CChar * target= NULL;
  
	if (ob && ob->Query(IS_CHAR))
	target=(CChar *) ob;
	
	  if (magic=="fugu")
	  {
	  
		}
		}
*********************/
SKILL_END;
