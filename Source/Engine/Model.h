#pragma once
#include "Mesh.h"


#ifdef ENGINE_EXPORTS
#define ENGINE_API __declspec(dllexport)
#else
#define ENGINE_API __declspec(dllimport)
#endif
namespace nu
{
	class ENGINE_API Model
	{
	public:
		Model() = default;
		Model(const std::vector<Mesh>& meshes) : m_meshes{meshes}{}

		void AddMesh(const Mesh& mesh) { m_meshes.push_back(mesh); }
		void SetMeshes(const std::vector<Mesh> meshes) { m_meshes = meshes; };
		const std::vector<Mesh>& GetMeshes() const { return m_meshes; }

	private:
		std::vector<Mesh> m_meshes;

	};

}