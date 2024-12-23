// SUnarmed.cpp: implementation of the CSUnarmed class.
//
//////////////////////////////////////////////////////////////////////

//unarmed.h -- ����ȭ��

SKILL_BEGIN(CSUnarmed);

virtual void create()
{
	set_name( "����ȭ��");
}

virtual CMapping * query_action(CChar * me)
{
	static char action[][80]=
	{
		"$N����ȥ�ݺݵĴ���$nһ���ơ�",
		"$N�����ש��������$n�����Դ��ϡ�",
		"$N���һ������ס$n�������������ᡣ",
		"$N���ɷ�˵������һ�ţ�����$n��С���ϡ�",
		"$N����ȭͷ����$n�ı��Ӵ��˻���",
		"$N������ָ��ʹ��Ĵ�����$n������ϡ�",
		"$N����ȥ�ݺݵ�����$nһ�š�",
		"$N�������£��ݺݵ�����$n���Դ��ϡ�",
	};
	
	m_actions.set("action", action[random(8)]);
	return & m_actions;
}

protected:
	CMapping m_actions;

SKILL_END;