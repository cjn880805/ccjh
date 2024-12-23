// Skill.h: interface for the CSkill class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SKILL_H__CF7B6A24_649A_11D4_98AB_0050BABC5212__INCLUDED_)
#define AFX_SKILL_H__CF7B6A24_649A_11D4_98AB_0050BABC5212__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Char.h"
#include "../combat/Combatd.h"

#define SKILL_USAGE_ATTACK	1
#define SKILL_USAGE_DEFENSE	2

#define LANSKILLMAXNUM		10

#define SKILL_BEGIN(skill_name)		class skill_name : public CSkill {	public:	skill_name(){};	virtual ~skill_name(){};	
#define SKILL_END		};	

#define PERFORM_BEGIN(skill_name)	class skill_name : public CSkill {	public:	skill_name(){};	virtual ~skill_name(){}; virtual LONG Query(int nAttr)	{	if(nAttr == PERFORM) 	return 1;	return CSkill::Query(nAttr);}
#define PERFORM_END		};	

class CSkill : public CMudObject
{
public:
	//������ʽ����
	typedef int MAGICFUNCTIONP(CChar * me, CContainer * ob);
	//�����ṹ
	typedef struct tagMagic{
		string	name;				//������
		int		mp;					//��Ҫmp��ֵ
		int		ap;					//��Ҫ��apֵ
		int		animate;			//������
		int		valid_cast;			//ʩ��ʱ��
		int		target;				//ʩ��Ŀ�� CAST_TO_OTHER, �������� CAST_TO_ME ���Լ� CAST_TO_NONE ��Ŀ�� CAST_TO_RANDOM ����Ŀ��

		MAGICFUNCTIONP * pFunc;		//ħ����ʽ

		tagMagic()
		{
			mp = 10;
			ap = 100;
			animate = 0;
			valid_cast = CAST_IN_NONE;
			target = CAST_TO_RANDOM;
		}
	}Magic_t;


public:
	static void start_powerup(CChar * me, int duration, int attack, int dodge, const char * msg);
	static void remove_powerup(CContainer * ob, LONG param1, LONG param2);
	virtual int valid_force(const char * arg);
	virtual int valid_combine(string combo);
	virtual int practice_skill(CChar * me);
	virtual int valid_enable(string usage);
	virtual const char * query_parry_msg(CContainer * weapon);
	virtual const char * query_dodge_msg(CChar * me);
	virtual const char * type();
	virtual int valid_effect(CChar * me, CContainer * weapon, char * action_name, int skill);
	virtual void skill_improved(CChar * me);
	virtual void create();
	virtual char * hit_ob(CChar * me, CChar * victim, LONG & damage);
	virtual CMapping * query_action(CChar * me);
	void DownLoad(CChar * me);
	virtual LONG Query(int nAttr);
	int Cast(string magic, CChar * me, CContainer * target = NULL);
	virtual int valid_learn(CChar * pMe);

	CSkill();
	virtual ~CSkill();

	enum{
		CAST_IN_NONE = 0,
		CAST_IN_COMMON,
		CAST_IN_COMBAT,
		CAST_IN_BOTH,
	};

	enum{
		CAST_TO_NONE = 0,
		CAST_TO_ME,			//�Լ�
		CAST_TO_OTHER,		//�Է�
		CAST_TO_RANDOM,		//��������		

		CAST_TO_FRIEND,		//�Ա��Ӷ�Աʹ��
		CAST_TO_TEAM,		//�Ա���ȫ��
		CAST_TO_OTHER_TEAM,	//�Եз�ȫ��		
	};

protected:
	static void lifehealeffect(CChar * me, CChar * target);
	Magic_t * add_magic(string magic, MAGICFUNCTIONP * pFunc);

	
	typedef map<string, Magic_t *, less<string> > CastList_t;
	CastList_t	m_MagicList;		//�����б�
};
#endif // !defined(AFX_SKILL_H__CF7B6A24_649A_11D4_98AB_0050BABC5212__INCLUDED_)
